//#include "number_systems.h"
//
//
//static uint8 a_power_b(uint8 a, uint8 o);
//
//
//void calculate_results_binary(void)
//{
//    uint64 temp = Num1;
//    uint16 Dec1 = ZERO, Dec2 = ZERO; 
//    uint8 remainder = ZERO, i = ZERO;
//    while(temp)
//    {
//      remainder = temp%10;
//      temp /= 10;
//      Dec1 += remainder * a_power_b(2, i);
//      ++i;
//    }
//    temp = Num2;
//    remainder = ZERO; i = ZERO;
//    while(temp)
//    {
//      remainder = temp%10;
//      temp /= 10;
//      Dec2 += remainder * a_power_b(2, i);
//      ++i;
//    }
//    switch(Operator){
//        case '+':
//            Num = Dec1 + Dec2;
//            break;
//        case '-':
//            Num = Dec1 - Dec2;
//            break;
//        case '*':
//            Num = Dec1 * Dec2;
//            break;
//        case '/':
//            Num = Dec1 / Dec2;
//            break;
//    }
//    uint8 binaryNumber[100];
//    i = ZERO;
//    temp = Num;
//    while(temp){
//        binaryNumber[i] = temp % 2;
//        temp = temp / 2;
//        i++;
//    }
//    for (int j = i - 1; j >= 0; j--)
//    {
//      if(j==i-1){
//      Num = binaryNumber[j];
//      }
//      else {
//        Num = Num * 10 + binaryNumber[j];
//      }
//    }
//    ret = lcd_4bit_set_cursor(&lcd, 1, 2);
//    ret = lcd_4bit_print_int(&lcd, Num);
//}
//
//uint16 a_power_b(uint8 a, uint8 b){
//    uint16 ans = 1;
//    for (int i = 0; i < b; i++)
//    {
//        ans *= a;
//    }
//    return ans;
//}
