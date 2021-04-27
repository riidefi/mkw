#pragma once

namespace UI {

class MessageGroup {
public:
  MessageGroup();
  // ...

private:
  void* mpBin;
  void* mpINF;
  void* mpDAT;
  void* mpSTR;
  void* mpID;
};

} // namespace UI
