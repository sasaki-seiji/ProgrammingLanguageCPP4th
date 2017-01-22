/*
 * multiple_try_lock.cpp
 *
 *  Created on: 2017/01/22
 *      Author: sasaki
 */


#include <cassert>
#include <thread>
#include <mutex>
#include <iostream>

int main()
{
  std::mutex mtx1;
  std::recursive_mutex mtx2;

  // 複数のミューテックスオブジェクトに対してtry_lock()を呼び出す
  {
    int result = std::try_lock(mtx1, mtx2);

    assert(result == -1); // 全てのtry_lock()呼び出しが成功
    std::cout << "result: " << result << std::endl;

    mtx1.unlock();
    mtx2.unlock();
  }

  // unique_lockに対してtry_lock()を呼び出す
  {
    std::unique_lock<std::mutex> lk1(mtx1, std::defer_lock);
    std::unique_lock<std::recursive_mutex> lk2(mtx2, std::defer_lock);

    int result = std::try_lock(lk1, lk2);

    assert(result == -1); // 全てのtry_lock()呼び出しが成功
    std::cout << "result: " << result << std::endl;
  }

  // 一部のtry_lock()が失敗する場合
  {
    // mtx2をロックしておく。
    std::lock_guard<std::recursive_mutex> lk2_main_thread(mtx2);

    std::thread th([&]
    {
      std::unique_lock<std::mutex> lk1(mtx1, std::defer_lock);
      std::unique_lock<std::recursive_mutex> lk2(mtx2, std::defer_lock);

      // 他のスレッドでmtx2をロックしているため、lk2のロックに失敗する。
      int result = std::try_lock(lk1, lk2);

      // lk2が失敗したので第2引数を示す1が返る(0始まり)
      assert(result == 1);
      std::cout << "result: " << result << std::endl;

      // lk2が失敗したので、std::try_lock()内でlk2より前にtry_lock()が
      // 成功した全てのミューテックスオブジェクトがunlock()される
      assert(!lk1.owns_lock());
      std::cout << "lk1.owns_lock(): " << lk1.owns_lock() << std::endl;
    });
    th.join();
  }
}


