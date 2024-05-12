class Button {
 public:
  Button() = default;
  ~Button() = default;
  virtual void RightClick();
  virtual void LeftClick();
  virtual void KeyboardClick();
  virtual void MouseOn();
  virtual void MouseOff();
};

template<typename T>
class AnimalButton :public Button {
};