class Resources {
 private:
  int money_ = 0;
  int eggs_ = 0;
  int meat_ = 0;
  int milk_ = 0;

 public:
  Resources() = default;
  ~Resources() = default;
  Resources& operator=(const Resources& r1) = default;
  Resources(int k) : money_(k), eggs_(0), meat_(0), milk_(0) {}

  void PayMoney(int x);
  void GiveEggs(int x); // возможно нужно возращать как раз x, а у самиз ресурсов убавлять?
  void GiveMeat(int x);
  void GiveMilk(int x);
  void GetMilk(int x);
  void GetEggs(int x);
  void GetMoney(int x);
  void GetMeat(int x);
};

