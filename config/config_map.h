// Copyright (c) 2012 The Tupler Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

// Author: Hector Gonzalez (hagonzal@gmail.com)

#ifndef CONFIG_CONFIGMAP_H_
#define CONFIG_CONFIGMAP_H_

#include <string>
#include <list>
#include <map>
#include <vector>

typedef std::pair<std::string, std::string> StringPair;

// Holds key value pairs used for configuration.
// The ConfigMap is the output of parsing a text config file.
// Values can be obtained from the ConfigMap as different types (e.g.
// string, int, double, string list, double list, etc).
class ConfigMap {
public:
  ConfigMap();
  ~ConfigMap();

  // Removes quotes from a string
  // RemoveQuotes("\"string\"") == "string"
  static std::string RemoveQuotes(const std::string *s);

  // Returns the head of a key.
  // PopLast("a.b.c") == "a.b"
  static std::string PopLast(const std::string& key);

  // Returns everything but the head
  // PopFirst("a.b.c") = "b.c"
  static std::string PopFirst(const std::string& key);

  // Returns the tail of a key
  // Tail("a.b.c") == "c"
  static std::string Last(const std::string& key);

  // Pushes a new part of a key
  // Push("a.b.c", "d") == "a.b.c.d"
  static std::string Push(const std::string& key, const std::string& s);

  // Returns a string representation of the map
  std::string ToString();

  // Returns true if the map contains the given key
  bool Contains(const std::string& key);

  // Returns the value of the given key. If the key is not present returns
  // the empty string
  std::string GetString(const std::string& key);

  // Retuns all key value pairs in the given section.
  void GetSection(const std::string& section, std::list<StringPair>& out);

  // Returns the value of the given key as a vector of strings. Each
  // string is added to out.
  void GetStringList(const std::string& key, std::vector<std::string>& out);

  // Returns the value of the given key as a vector of doubles. Each double is
  // added to out.
  void GetDoubleList(const std::string& key, std::vector<double>& out);

  // Returns the value of the given key as a double.
  double GetDouble(const std::string& key);

  // Returns the value of the given key as an integer.
  int GetInt(const std::string& key);

  // Adds a new entry to the map
  void AddEntry(const std::string& key, const std::string value);

  // Removes an entry from the map
  void RemoveEntry(const std::string& key);

  // Makes a copy of the object
  ConfigMap * Copy();

  void GetContent(std::list<StringPair>& out);

  // Overrides the entries on this map with those in other. Ignores the
  // first component of each key in other.
  void Override(ConfigMap *other);

private:
  // Disallow copy and assign
  explicit ConfigMap(const ConfigMap& copy_from_me);
  void operator=(const ConfigMap&);

  std::map<std::string, std::string> data_;
};

#endif /* CONFIG_CONFIGMAP_H_ */
