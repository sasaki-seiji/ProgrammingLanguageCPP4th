/*
 * random_device.cpp
 *
 *  Created on: 2017/01/15
 *      Author: sasaki
 */

#include <iostream>
#include <cassert>
#include <string>
#include <random>

// candidate_chars : パスワードに含める文字の集合
// length : パスワードの長さ
std::string create_password(const std::string& candidate_chars, std::size_t length)
{
  assert(!candidate_chars.empty());

  // 非決定的な乱数生成器を使用する
  std::random_device engine;

  // パスワード候補となる文字集合の範囲を一様分布させる
  std::uniform_int_distribution<std::size_t> dist(0, candidate_chars.size() - 1);

  std::string password;
  for (std::size_t i = 0; i < length; ++i) {
    // パスワード候補の文字集合から、ランダムな一文字を選択する
    std::size_t random_index = dist(engine);
    char random_char = candidate_chars[random_index];

    // 選択した文字を、パスワード文字列に追加する
    password += random_char;
  }
  return password;
}

int main()
{
  std::string candidate_chars = "abcdefghijklmnopqrstuvwxyz";
  std::size_t length = 8;

  std::string password = create_password(candidate_chars, length);
  std::cout << password << std::endl;
}

