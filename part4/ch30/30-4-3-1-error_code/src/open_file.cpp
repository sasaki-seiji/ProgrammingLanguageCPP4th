/*
 * open_file.cpp
 *
 *  Created on: 2017/08/06
 *      Author: sasaki
 */

#include "open_file.h"
#include <system_error>
#include <fstream>
#include <iostream>
using namespace std;

#include <sys/types.h>
#include <sys/stat.h>

pair<string,string> split_into_directory_and_name(const string&);
error_code does_directory_exist(const string&);

void open_file(const string& path,ofstream& ofs)
{
	auto dn = split_into_directory_and_name(path);
	cout << "dir: " << dn.first << ", file: " << dn.second << endl;

	if (error_code err {does_directory_exist(dn.first)}) {
		if (err==errc::permission_denied) {
			cout << "permission denied" << endl;
		}
		else if (err==errc::not_a_directory) {
			cout << "not a directory" << endl;
		}
		throw system_error(err);
	}

	ofs.open(path);
}

pair<string,string> split_into_directory_and_name(const string& path)
{
	size_t found = path.find_last_of("/");
	if (found == string::npos) {
		return make_pair(string{"."}, path);
	}
	return make_pair(path.substr(0,found),path.substr(found+1));
}

error_code does_directory_exist(const string& dir)
{
	struct stat info;
	const char* name = dir.c_str();

	if (stat(name, &info) != 0)
		return make_error_code(errc::permission_denied);
	else if ((info.st_mode & S_IFDIR) == 0)
		return make_error_code(errc::not_a_directory);

	return error_code{};
}
