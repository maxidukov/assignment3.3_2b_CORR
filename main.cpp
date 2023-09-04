#include <iostream>

class Counter {
  //public:
  int value;
  void incr() { value++; }
  void decr() { value--; }
  void display_val() { std::cout << value << std::endl; }

public:
  Counter() { value = 1; }
  Counter(int num) { value = num; }
  bool work() {
    bool retval = true;
    char command = ' ';
    std::string input;
    std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
    std::cin >> input;
    // std::cin>>command;
    command = input[0];
    switch (command) {
    case '+':
      incr();
      break;
    case '-':
      decr();
      break;
    case '=':
      display_val();
      break;
    case 'x':
      retval = false;
      break;
    default:
      std::cout << "Только '+', '-', '=' или 'x' (латинская буква)!\n";
      break;
    }
    return retval;
  }
};

//void get_counter(Counter*);
Counter get_counter();

int main() {
  //Counter* pcounter;
  Counter my_counter = get_counter();
  while (my_counter.work()) {;}
  std::cout << "До свидания!\n";

  return 0;
}

  Counter get_counter(){
    std::string choice = "";
    while(1){
       std::cout<<"Вы хотите указать начальное значение счётчика? Введите да или нет: ";
       std::cin>>choice;
       //std::cout<<choice<<std::endl;
       if(choice == "да"){
         int num;
         std::cout<<"Введите начальное значение счётчика: ";
         std::cin>>num;
         Counter my_counter(num);
         return my_counter;
         //pcounter = &my_counter;
       }else if(choice == "нет"){
         Counter my_counter;
         return my_counter;
         //pcounter = &my_counter;
       }else{
         std::cout<<"Пожалуйста, введите 'да' или 'нет'\n";
       }
    }
  }
