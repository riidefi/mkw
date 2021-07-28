#pragma once

#include <nw4r/ut/utList.hpp>

namespace Kart {

class KartAccessor;

class KartComponent {
public:
  static void initList();

  static void setupInList(KartAccessor* accessor);

  KartComponent();

private:
  static nw4r::ut::List sList;

  KartAccessor* mAccessor;
  nw4r::ut::Node mNode;
};

} // namespace Kart
