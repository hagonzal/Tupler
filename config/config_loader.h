// Copyright (c) 2012 The Tupler Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

// Author: Hector Gonzalez (hagonzal@gmail.com)

#ifndef CONFIG_CONFIGLOADER_H_
#define CONFIG_CONFIGLOADER_H_

#include <fstream>
#include <string>
#include <list>
#include <map>
#include <iostream>

typedef std::list<std::string> StringList;

// Loads a configuration file from disk, recursively loading included files.
class ConfigLoader {
public:
  ConfigLoader();
  ~ConfigLoader();

  void Load(const std::string& file_name, StringList& out);

private:
  // Disallow copy and assign
  explicit ConfigLoader(const ConfigLoader& copy_from_me);
  void operator=(const ConfigLoader&);

  StringList::iterator LoadInternal(const std::string& file_name,
      StringList& lines, StringList::iterator it);

  std::string ExtractInclude(const std::string& line);
  int CleanLine(std::string& line, char *out);
};

#endif /* CONFIG_CONFIGLOADER_H_ */
