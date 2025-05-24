#pragma once

namespace UI {

struct TypeInfo {
  TypeInfo* base;
};

template <typename T> struct Deferred {
  char data[sizeof(T)];

  T& get() { return *reinterpret_cast<T*>(&data); }
  const T& get() const { return *reinterpret_cast<const T*>(&data); }

  operator T&() { return get(); };
  operator const T&() const { return get(); };
};

} // namespace UI
