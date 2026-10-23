#include <iostream>
#include <string>

class String {
 private:
  struct Data {
    std::string str;
    std::size_t count = 1;

    Data(const std::string& s) : str(s) {}
  };

  Data* data;

  void copy() {
    if (data->count > 1) {
      Data* temp = new Data(data->str);
      --(data->count);
      data = temp;
    }
  }

 public:
  String(const std::string& s) { data = new Data(s); }

  String(const String& other) {
    data = other.data;
    ++(data->count);
  }

  ~String() {
    --(data->count);

    if (data->count == 0) {
      delete data;
    }
  }

  String& operator=(const String& other) {
    if (this != &other) {
      --(data->count);

      if (data->count == 0) {
        delete data;
      }

      data = other.data;
      ++(data->count);
    }

    return *this;
  }

  const std::string& get() const { return data->str; }

  void set(const std::string& s) {
    copy();
    data->str = s;
  }
};

int main() {
  String a("Hello");
  String b = a;

  std::cout << a.get() << '\n';
  std::cout << b.get() << '\n';

  b.set("World");

  std::cout << a.get() << '\n';
  std::cout << b.get() << '\n';

  return 0;
}