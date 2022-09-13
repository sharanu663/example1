#include<iostream>
#include<limits>
#include<new>
#include <utility>

#define TEST_STD_VER 14
struct Compare_lhs_and_rhs 
{
    int n;
};

struct test 
{
    int i;
};
 
void test_limits(void);
void test_new(void);
void test_typeinfo(void);
void test_initializer(void);
void test_exchange(void);
void test_forward(void);
void test_rel_ops(void);
void test_swap(void);
void test_integar_sequence(void);
bool operator<(const Compare_lhs_and_rhs& lhs, const Compare_lhs_and_rhs& rhs);
bool operator==(const Compare_lhs_and_rhs& lhs, const Compare_lhs_and_rhs& rhs);  


  
int main()
{

std::cout<<"test_limits"<<std::endl;
test_limits();                       
    
std::cout<<"test_typeinfo"<<std::endl;
test_typeinfo();
	
std::cout<<"test_initializer"<<std::endl;
test_initializer();
	 
std::cout<<"test_exchange"<<std::endl;
test_exchange();

std::cout<<"test_forward"<<std::endl;
test_forward();
	 
std::cout<<"test_rel_ops"<<std::endl;
test_rel_ops();
	 
std::cout<<"test_swap"<<std::endl;
test_swap();
	 
std::cout<<"test_integar_sequence"<<std::endl;
test_integar_sequence();

std::cout<<"test_new"<<std::endl;
test_new();

}

void test_limits(void)
{
  
  std::numeric_limits<bool> bool_range;

  bool min_value=bool_range.min(); 
  std::cout<<"min_value: "<<min_value<<std::endl;

  bool max_value=bool_range.max(); 
  std::cout<<"max_value: "<<max_value<<std::endl;

  bool low_value=bool_range.lowest();
  std::cout<<"low_value: "<<low_value<<std::endl;

  bool esp_value=bool_range.epsilon();
  std::cout<<"esp_value: "<<esp_value<<std::endl;

  bool round_err_value=bool_range.round_error();
  std::cout<<"round_err_value: "<<round_err_value<<std::endl;

  bool infi_value=bool_range.infinity();
  std::cout<<"infi_value: "<<infi_value<<std::endl;

  bool quiet_value=bool_range.quiet_NaN();
  std::cout<<"quiet_value: "<<quiet_value<<std::endl;

  bool signaling_value=bool_range.signaling_NaN();
  std::cout<<"signaling_value: "<<signaling_value<<std::endl;

  bool denorm_min_value=bool_range.denorm_min();
  std::cout<<"denorm_min_value: "<<denorm_min_value<<std::endl;

}

void  test_typeinfo(void)
{
 typedef int int_type;
 if(typeid(int) == typeid(int_type))
    std::cout<<"both data type are same"<<std::endl;
 if(typeid(int) != typeid(char))
    std::cout<<"both data type are different"<<std::endl;
}

void test_initializer(void)
{
 std::initializer_list<int> init_list={10,20,30,40};
 //init_list = {10, 20, 30};
 for (const int* it=init_list.begin(); it!=init_list.end(); it++)
 {
   std::cout<<*it<<" ";
 }
 std::cout<<std::endl;
}

void test_exchange(void)
{
  int  var = 12;
 if(std::exchange (var,23 ) == 12 );
   std::cout<<"new_value of var="<<var<<std::endl;
}

void test_forward(void)
{
  const int cx = 101;
  constexpr int i2 = std::forward<int>(42);
  if((std::forward<int>(42) == 42)&&(std::forward<const int&>(i2)== 42)&&(std::forward<const int>(i2) == 42))
    
     std::cout<<"forward initialization successfuly"<<std::endl;
  else 
      std::cout<<"forward initialization failed"<<std::endl;
	  
  if((std::forward<const int&>(cx) == 101)&&(std::forward<const int>(cx)  == 101))
     std::cout<<"forward initialization successfuly"<<std::endl;
  else 
	 std::cout<<"forward initialization failed"<<std::endl;;
}

void test_rel_ops(void)
{
 using namespace std::rel_ops;
 Compare_lhs_and_rhs lhs_obj1 = {1};
 Compare_lhs_and_rhs rhs_obj2 = {2};
 std::cout << "not equal?     : " << (lhs_obj1 != rhs_obj2)<< std::endl;
 std::cout << "greater?       : " << (lhs_obj1 > rhs_obj2)<< std::endl;
 std::cout << "less equal?    : " << (lhs_obj1 <= rhs_obj2)<< std::endl;
 std::cout << "greater equal? : " << (lhs_obj1 >= rhs_obj2)<< std::endl;
}

void test_swap(void)
{

  int var1 = 5;
  int var2 = 2;
 std::cout<<"Before swap"<<std::endl;
 std::cout <<"var1 ="<<var1<<std::endl;
 std::cout <<"var2 ="<<var2<<std::endl;
 std::swap(var1,var2);
 std::cout<<"After swap"<<std::endl;
 std::cout <<"var1 ="<<var1<<std::endl;
 std::cout <<"var2 ="<<var2<<std::endl;

}

void test_integar_sequence(void)
{

 using int3    = std::integer_sequence<int, 3, 2, 1>;
 using size1   = std::integer_sequence<std::size_t, 7>;
 using ushort2 = std::integer_sequence<unsigned short, 4, 6>;
 using bool0   = std::integer_sequence<bool>;

 if(int3::size() == 3)
   std::cout<<"int3 size is correct"<< std::endl;
 else
   std::cout<<"int3 size is wrong"<< std::endl;
   
 if(size1::size() == 1) 
	std::cout<<"size1 size is correct"<< std::endl; 
 else
	std::cout<<"size1 size is wrong"<< std::endl;
	  
 if(ushort2::size() == 2)
	std::cout<<"ushort2 size is correct"<< std::endl;
 else
	std::cout<<"ushort2 size is wrong"<< std::endl;
	   
 if(bool0::size() == 0)
	std::cout<<"bool0 size is correct"<< std::endl;
 else
	std::cout<<"bool0 size is wrong"<< std::endl;

}

void  test_new(void)
{
 
 void* place = operator new (sizeof(test));
 //char place[sizeof(test)];
 test* p = new (place) test();
 std::cout<<"place="<<place<<std::endl;
 std::cout<<"p="<<p<<std::endl;

}

bool operator==(const Compare_lhs_and_rhs& lhs, const Compare_lhs_and_rhs& rhs)
{
    return lhs.n == rhs.n;
}
 
bool operator<(const Compare_lhs_and_rhs& lhs, const Compare_lhs_and_rhs& rhs)
{
    return lhs.n < rhs.n;
}






































/*#include<iostream>
#include<limits>
#include<new>
#include <utility>
 
void test_limits(void);
void test_new(void);
void test_typeinfo(void);
void test_initializer(void);
void test_exchange(void);
void test_forward(void);
void test_rel_ops(void);
void test_swap(void);
void test_integar_sequence(void);
bool operator<(const Compare_lhs_and_rhs& lhs, const Compare_lhs_and_rhs& rhs);
bool operator==(const Compare_lhs_and_rhs& lhs, const Compare_lhs_and_rhs& rhs);  

struct Compare_lhs_and_rhs 
{
    int n;
};

struct test 
{
    int i;
};
  
int main()
{

std::cout<<"test_limits"<<std::endl;
test_limits();                       
    
std::cout<<"test_typeinfo"<<std::endl;
test_typeinfo();
	
std::cout<<"test_initializer"<<std::endl;
test_initializer();
	 
std::cout<<"test_exchange"<<std::endl;
test_exchange();

std::cout<<"test_forward"<<std::endl;
test_forward();
	 
std::cout<<"test_rel_ops"<<std::endl;
test_rel_ops();
	 
std::cout<<"test_swap"<<std::endl;
test_swap();
	 
std::cout<<"test_integar_sequence"<<std::endl;
test_integar_sequence();

std::cout<<"test_new"<<std::endl;
test_new();

}

void test_limits(void)
{
  
  std::numeric_limits<bool> bool_range;

  bool min_value=bool_range.min(); 
  std::cout<<"min_value: "<<min_value<<std::endl;

  bool max_value=bool_range.max(); 
  std::cout<<"max_value: "<<max_value<<std::endl;

  bool low_value=bool_range.lowest();
  std::cout<<"low_value: "<<low_value<<std::endl;

  bool esp_value=bool_range.epsilon();
  std::cout<<"esp_value: "<<esp_value<<std::endl;

  bool round_err_value=bool_range.round_error();
  std::cout<<"round_err_value: "<<round_err_value<<std::endl;

  bool infi_value=bool_range.infinity();
  std::cout<<"infi_value: "<<infi_value<<std::endl;

  bool quiet_value=bool_range.quiet_NaN();
  std::cout<<"quiet_value: "<<quiet_value<<std::endl;

  bool signaling_value=bool_range.signaling_NaN();
  std::cout<<"signaling_value: "<<signaling_value<<std::endl;

  bool denorm_min_value=bool_range.denorm_min();
  std::cout<<"denorm_min_value: "<<denorm_min_value<<std::endl;

}

void  test_typeinfo(void)
{
 typedef int int_type;
 if(typeid(int) == typeid(int_type))
    std::cout<<"both data type are same"<<std::endl;
 if(typeid(int) != typeid(char))
    std::cout<<"both data type are different"<<std::endl;
}

void test_initializer(void)
{
 std::initializer_list<int> init_list={10,20,30,40};
 init_list = { 10, 20, 30 };
 for (const int* it=init_list.begin(); it!=init_list.end(); it++)
 {
   std::cout<<*it<<" ";
 }
 std::cout<<std::endl;
}

void test_exchange(void)
{
 uint8_t  var = 12;
 if(std::exchange (var, 23 ) == 12 );
   std::cout<<"new_value of var="<<var<<std::endl;
}

void test_forward(void)
{
#if TEST_STD_VER > 11
 {
  const int cx = 101;
  constexpr int i2 = std::forward<int>(42);
  if((std::forward<int>(42) == 42)&&(std::forward<const int&>(i2) == 42)&&(std::forward<const int>(i2) == 42)&& (std::forward<int&&>(i2) == 42)&&(std::forward<const int&&>(i2) == 42))
     std::cout<<"forward initialization successfuly"<<std::endl;
  else 
      std::cout<<"forward initialization failed"<<std::endl;
	  
  if((std::forward<const int&>(cx) == 101)&&(std::forward<const int>(cx)  == 101))
     std::cout<<"forward initialization successfuly";
  else 
	 std::cout<<"forward initialization failed"<<std::endl;
 }
#endif
#if TEST_STD_VER == 11 && defined(_LIBCPP_VERSION)
 {
   constexpr int i2 = std::forward<int>(42);
   if((std::forward<int>(42) == 42)&&(std::forward<const int&>(i2) == 42));
     std::cout<<"";
 }
#endif
}

void test_rel_ops(void)
{
 using namespace std::rel_ops;
 Compare_lhs_and_rhs lhs_obj1 = {1};
 Compare_lhs_and_rhs rhs_obj2 = {2};
 std::cout << "not equal?     : " << (lhs_obj1 != rhs_obj2)<< std::endl;
 std::cout << "greater?       : " << (lhs_obj1 > rhs_obj2)<< std::endl;
 std::cout << "less equal?    : " << (lhs_obj1 <= rhs_obj2)<< std::endl;
 std::cout << "greater equal? : " << (lhs_obj1 >= rhs_obj2)<< std::endl;
}

void test_swap(void)
{

 uint8_t var1 = 5;
 uint8_t var2 = 2;
 std::cout<<"Before swap"<<std::endl;
 std::cout <<"var1 ="<<var1<<std::endl;
 std::cout <<"var2 ="<<var2<<std::endl;
 std::swap(a,b);
 std::cout<<"After swap"<<std::endl;
 std::cout <<"var1 ="<<var1<<std::endl;
 std::cout <<"var2 ="<<var2<<std::endl;

}

void test_integar_sequence(void)
{

 using int3    = std::integer_sequence<int, 3, 2, 1>;
 using size1   = std::integer_sequence<std::size_t, 7>;
 using ushort2 = std::integer_sequence<unsigned short, 4, 6>;
 using bool0   = std::integer_sequence<bool>;

 if(int3::size() == 3)
   std::cout<<"int3 size is correct"<< std::endl;
 else
   std::cout<<"int3 size is wrong"<< std::endl;
   
 if(size1::size() == 1) 
	std::cout<<"size1 size is correct"<< std::endl; 
 else
	std::cout<<"size1 size is wrong"<< std::endl;
	  
 if(ushort2::size() == 2)
	std::cout<<"ushort2 size is correct"<< std::endl;
 else
	std::cout<<"ushort2 size is wrong"<< std::endl;
	   
 if(bool0::size() == 0)
	std::cout<<"bool0 size is correct"<< std::endl;
 else
	std::cout<<"bool0 size is wrong"<< std::endl;

}

void  test_new(void)
{
 
 void* place = operator new (sizeof(test));
 test* p = new (place) test();
 std::cout<<"place="<<place<<std::endl;
 std::cout<<"p="<<p<<std::endl;

}

bool operator==(const Compare_lhs_and_rhs& lhs, const Compare_lhs_and_rhs& rhs)
{
    return lhs.n == rhs.n;
}
 
bool operator<(const Compare_lhs_and_rhs& lhs, const Compare_lhs_and_rhs& rhs)
{
    return lhs.n < rhs.n;
}*/



















