// Copyright (c) 2012 The Tupler Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.

// Author: Hector Gonzalez (hagonzal@gmail.com)

#include "config/constant.h"

Constant::Constant(int type, const std::string *svalue) {
  type_ = type;

  if (svalue == NULL) {
    svalue_ = "";
  } else {
    svalue_ = *svalue;
  }
}

Constant::~Constant() {
}

int Constant::GetInt() {
  return ivalue_;
}

float Constant::GetFloat() {
  return fvalue_;
}

std::string Constant::GetString() {
  return svalue_;
}

std::string Constant::ToString() {
  return svalue_;
}

int Constant::GetType() {
  return type_;
}
