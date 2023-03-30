#pragma once
#include <iostream>
#include <fstream>
#include "farm.hpp"

void Save_data(Base& base) {
  std::ofstream out;
  out.open("data.txt");
  if (out.is_open()) {
    out << "Animals:" << std::endl;
    for (auto it = base.Pets_.begin(); it != base.Pets_.end(); it++) {
      out << (it->first) << " "; 
      out << (it->second) << std::endl;
    }
    out << "Buildings:" << std::endl;
    for (auto it = base.Buildings_.begin(); it != base.Buildings_.end(); it++) {
      out << (it->first) << " "; 
      out << (it->second) << std::endl;
    }
  }
  out.close();
}














