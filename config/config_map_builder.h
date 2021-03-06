// Copyright (c) 2012 The Tupler Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

// Author: Hector Gonzalez (hagonzal@gmail.com)

#ifndef CONFIG_MAP_BUILDER_H_
#define CONFIG_MAP_BUILDER_H_

#include <string>

#include "config/config_map.h"
#include "config/constant.h"

typedef std::pair<std::string, std::string> StringPair;

// Builds a ConfigMap. Used by the parser (tuple.y) to build a config map
// from a config file.
class ConfigMapBuilder {
public:
  ConfigMapBuilder();
  ~ConfigMapBuilder();

  // Handles the start of a new section.
  void StartSection(std::string *section, std::string *parent);

  // Hanldes the end of a section.
  void EndSection(std::string *section);

  // Handles a key value pair in a section
  void AddKeyValue(std::string *key, Constant * node);

  // Returns the ConfigMap
  ConfigMap *GetMap();
private:
  // Current section
  std::string section_;

  // Map with key value pairs
  ConfigMap config_map_;
};

#endif /* CONFIG_MAP_BUILDER_H_ */
