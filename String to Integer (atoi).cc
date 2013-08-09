class Solution {
public:
   int atoi(const char *str) {
       bool nev = false;
       int ans = 0;
       int i;
       for (i = 0; str[i] !='\0'; i++)
           if (str[i] != ' ') break;
       if (str[i] == '+' || str[i] == '-')
       {
           nev = (str[i] == '-');
           i++;
       }
       for (i; str[i] != '\0'; i++)
       {
           int ch = str[i] - '0';
           if (ch < 0 || ch > 9) return ans;
           if (nev)
           {                  
               int temp = (0x80000000 + ch);
               temp /= 10;
               if (ans < temp) return 0x80000000;
               ans = ans * 10 - ch;
               
           }
           else
           {
               int temp = 0x7fffffff - ch;
               if (ans > (0x7fffffff - ch) / 10) return 0x7fffffff;
               ans = ans * 10 + ch;
           }            
       }        
       return ans;
       
   }
};