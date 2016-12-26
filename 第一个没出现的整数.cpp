#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <stack>
#define MAX_N 1000001
using namespace std;
stack<int> ans;
main()

{

   int left_fish;

   int s;

   int flag;

   int i,n;



   for (n = 1; n < MAX_N; n++) {

           left_fish = 5*n+1;

           s = left_fish;

           flag = 1;



           for (i=0; i<4; i++) {

               if ((5*s)%4 == 0) {

                   s = (5*s)/4+1;

            } else {

                flag = 0;

               break;

            }

        }



           if (flag == 1) {

                   printf("Fish which were gotten by fishers

                   at least are %d\n",s);

                   break;

            }

    }

}
