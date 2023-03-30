#pragma once
#include <iostream>
#include <fstream>
#include <unordered_map>
#include "farm.hpp"
std::unordered_map<std::string, Animal*>Pets_; 
std::unordered_map<std::string, TypeOfBuildings>Buildings_;

void Save_data() {
  std::ofstream out;
  out.open("data.txt");
  if (out.is_open()) {
    out << "Animals:" << std::endl;
    for (auto it = Pets_.begin(); it != Pets_.end(); it++) {
      out << (it->first) << " "; 
      out << (it->second) << std::endl;
    }
    out << "Buildings:" << std::endl;
    for (auto it = Buildings_.begin(); it != Buildings_.end(); it++) {
      out << (it->first) << " "; 
      out << (it->second) << std::endl;
    }
  }
  out.close();
}














