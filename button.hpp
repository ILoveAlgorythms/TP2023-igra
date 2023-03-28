class Button {
 public:
  Button() = default;
  ~Button() = default;
  virtual void RightClick();
  virtual void LeftClick();
  virtual void KeyboardClick(); // навели мышь и нажали
  virtual void MouseOn(); // навели мышь
  virtual void MouseOff(); // убрали мышь
};

template<typename T>
class AnimalButton :public Button {
 private:
  T
 public:
  
}