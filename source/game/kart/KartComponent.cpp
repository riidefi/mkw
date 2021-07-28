#include "KartComponent.hpp"
#include <cstddef>

namespace Kart {

void KartComponent::initList() {
  List_Init(&sList, offsetof(KartComponent, mNode));
}

void KartComponent::setupInList(KartAccessor* accessor) {
  KartComponent* component = nullptr;
  while ((component = (KartComponent*)List_GetNext(&sList, component))) {
    component->mAccessor = accessor;
  }
}

KartComponent::KartComponent() {
  mAccessor = nullptr;

  List_Append(&sList, this);
}

} // namespace Kart
