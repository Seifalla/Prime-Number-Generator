
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <time.h>

using namespace std;

vector<int> add(vector<int> x, vector<int> y);
bool greaterThan(vector<int> r, vector<int> y);
vector<int> subtract(vector<int>  x, vector<int> y);
int binary(vector<int> x);
vector<int> multiply(vector<int> x, vector<int> y);
void divide(vector<int> x, vector<int> y, vector<int> &q, vector<int> &r);
vector<int> modExp(vector<int> N, vector<int> x, vector<int> y);
vector<int> read_file(ifstream &file, int inputs);
vector<int> RandomGenerator(int n);
bool primalityTest(vector<int> M);
vector<int> sqrt(vector<int> M);
bool primalityCheck(vector<int> n);

int main(int argc,char *argv[]){

  vector<int> N(0);

  int rand = 0;

  clock_t t;

  t = clock();          

  for(int i = 0; i < 100; i++){

  N = RandomGenerator(16);

  while(!primalityTest(N))

	N = RandomGenerator(16);

  if(primalityCheck(N))

  	cout<<"Prime"<<endl;
  else

	cout<<"not prime"<<endl;

  for(int i = N.size() - 1; i >= 0; i--)

	cout<< N[i];  

  cout<<endl; 
  }

   t = clock() - t;
  cout<<"It took me"<<((float)t)/CLOCKS_PER_SEC<<"seconds"<<endl;

    for(int i = 0; i < 10; i++){

  N = RandomGenerator(16);

  rand = 1 ;

  while(!primalityTest(N)){

	rand ++;

        N = RandomGenerator(16);
  }

  if(primalityCheck(N))

        cout<<"Prime"<<endl;
  else

        cout<<"not prime"<<endl;

  cout<<"number of generated random numbers: "<<rand<<endl;

  for(int i = N.size() - 1; i >= 0; i--)

        cout<< N[i];

  cout<<endl;
  }

 t = clock() - t;
 cout<<"It took me"<<((float)t)/CLOCKS_PER_SEC<<"seconds"<<endl;
    for(int i = 0; i < 10; i++){

  rand = 1;

  N = RandomGenerator(32);

  while(!primalityTest(N)){

	rand ++;

        N = RandomGenerator(32);
  }

  if(primalityCheck(N))

        cout<<"Prime"<<endl;
  else

        cout<<"not prime"<<endl;

  cout<<"number of generated random numbers: "<<rand<<endl;

  for(int i = N.size() - 1; i >= 0; i--)

        cout<< N[i];

  cout<<endl;
  }

 t = clock() - t;
 cout<<"It took me"<<((float)t)/CLOCKS_PER_SEC<<"seconds"<<endl;

  for(int i = 0; i < 3; i++){

  N = RandomGenerator(64);

  rand = 1;

  cout<<"Number generated."<<endl;

  cout<<"testing..."<<endl;

  while(!primalityTest(N)){

	cout<<"fail"<<endl;

	rand ++;

        N = RandomGenerator(64);
  }

  cout<<"number of generated random numbers: "<<rand<<endl;

  for(int i = N.size() - 1; i >= 0; i--)

        cout<< N[i];

  cout<<endl;
  }

   t = clock() - t;
  cout<<"It took me"<<((float)t)/CLOCKS_PER_SEC<<"seconds"<<endl;

  for(int i = 0; i < 3; i++){

  N = RandomGenerator(128);

  rand = 1;

  cout<<"random number generated"<<endl;

  cout<<"testing"<<endl;

  while(!primalityTest(N)){

	cout<<"fail"<<endl;

   	rand++;

        N = RandomGenerator(128);
  }

  cout<<"number of generated random numbers: "<<rand<<endl;

  for(int i = N.size() - 1; i >= 0; i--)

        cout<< N[i];

  cout<<endl;
  }

 t = clock() - t;
 cout<<"It took me"<<((float)t)/CLOCKS_PER_SEC<<"seconds"<<endl;
        
  return 0;
}

// this function checks if the randomly generated number is a prime by trying all divisors up to the square root of the number

bool primalityCheck(vector<int> n)
{
    vector<int> i(0), r(0), q(0), two(0);

    vector<int> root = sqrt(n);

    i.push_back(1);
    i.push_back(1);

    two.push_back(0);
    two.push_back(1);
    
    bool prime = true;

    divide(n, two, q, r);    
    
    if(r.size() == 0)
    
        prime = false;

    r.clear(), q.clear();
        
    while(prime && greaterThan(root, i)){

  	divide(n, i, q, r);
        
        if(r.size() == 0)
        
            prime = false;

        r.clear(), q.clear();
            
        i = add(i,two);
    }

    return prime;
    
}
// This function estimates the value of the square root using the equation: estimate = ((estimate + input/estimate)/2)
vector<int> sqrt(vector<int> M){

   int a = 1;
   vector<int>  root(0), product(0), q(0), r(0),
   estRoot(0), one(1,1), sum(0);
   vector<int> two(0);
   two.push_back(0);
   two.push_back(1);

   divide(M, two, q, r);

   root = q;

   r.clear(), q.clear();

   while(a != 0){

        product = multiply(root,root);

        estRoot = subtract(product,M);

        if(greaterThan(one, estRoot))

                a = 0;
        else if(greaterThan(M,product))

                a = 0;

            else{
              divide(M, root, q, r);
              sum = add(root, q);
              r.clear(), q.clear();
              divide(sum, two, q, r);
              root = q;
              r.clear(), q.clear();
            }
    }

    return root;
}

// this function tests primality. Since the numbers you will be testing are randomly generated, we are going to use the first the single test: 3^(N −1) ≡ 1(mod N).      
bool primalityTest(vector<int> M){

	vector<int> x(0), y(0),  one(0), r(0);
	bool prime = false;

	x.push_back(1);
  	x.push_back(1);	
	
	one.push_back(1);

	y = subtract(M, one);	

	r = modExp(M, x, y);

	if(r.size() == 1)

		if(r[0] == 1)
			prime = true;
		else
                	prime = false;
	else
		prime = false;

	return prime;
}

//this function takes a file object as a parameter 
//and store the numbers in the file in a vector
//and returns that vector.

vector<int> read_file(ifstream &file, int inputs){

                vector<int> g(0);

		int lines = 0;

                char my_character = '0';

		string line;

                int n = 0;

                while (file){

                    if(inputs == 1){

                        while(file && my_character != '\n')

                                file.get(my_character);

                        inputs --;

                    }
                    
                    else if(inputs == 2){

                            while(file && lines < 2){

                                getline(file, line);

				lines ++;
			    }

                            inputs = inputs - 2;

                        }

                    file.get(my_character);

                    if(my_character == ' ' || my_character == '\n')

                        break;

                    if (my_character != ' ' || my_character != '\n'){

                        n = my_character - '0';

                        g.push_back(n);
                    }

                }

                file.close();

                return g;

}
/* Input: an integer L representing the length of the number

   Output: a randomly generated number

Set the first and last bit to 1
Initialize the counter to 0
Create a vector N of length L
While counter is less than the length:
	Use the Unix rand() function to generate a random number
	If it’s even, set the current bit to 0
	If it’s odd, set the current bit to 1
Return N */

vector<int> RandomGenerator(int n){

    vector<int> PrimeTest(0);
    clock_t t;
    int bit;
    int t1;
    t = clock();
    for(int i = 0; i<=(n-1); i++){1
        if((t1%2) == 0)
            bit = 0;
        else
            bit = 1;
        PrimeTest.push_back(bit);
        t = clock() - t;
        t1 = t;
    }
    PrimeTest[0] = 1;
    PrimeTest[PrimeTest.size()-1] = 1;
     
    return PrimeTest;
}

/* this function reads three numbers from a
text file: x, y, N. And it displays
x^(Y) modN
*/    
vector<int> modExp(vector<int> N, vector<int> x, vector<int> y){
   vector<int> q(0), r(0), z(0);
   
   z.push_back(1);
   
   for(int i = (y.size() - 1); i >= 0; i--){     
       
       z = multiply(z, z);
       divide(z, N, q, r);
       z = r;
       r.clear(), q.clear();
       if(y[i] == 1){
           
           z = multiply(z, x);
           divide(z, N, q, r);           
           z = r;
           r.clear(), q.clear();
       }
   }
   
   return z;
   
}
/* This functions divides an integer x by another integer y != 0 by finding a quotient q and a remainder r, 
where x = yq + r and r < y.*/   

void divide(vector<int> x, vector<int> y, vector<int> &q, vector<int> &r){

   vector<int> one(1,1);
   
   int size = 0;

   for(int i = x.size() - 1; i >= 0; i--){

       q.insert (q.begin(), 0);

       r.insert (r.begin(), 0);              

       size = q.size() - 1;

       while(q[size] == 0 && size > 0){

                q.pop_back();

                size = q.size() - 1;
        }

        size = r.size() - 1;

        while(r[size] == 0 && size > 0){

                r.pop_back();

                size = r.size() - 1;
        }

       if(x[i] == 1)

            r = add(r, one);

       if(greaterThan(r, y)){

            r = subtract(r, y);
            q = add(q, one);
       }

   }
}

/* The operand with fewer digits is padded with 0’s

	Every two elements in the vectors are added

	If both operands are 1’s, the sum will be set to 1 and the carry will be set to 0

	If both operands are 1’s and the carry-in is also a 1, the sum will be set to 1 and the carry will be set to 1*/

vector<int> add(vector<int> x, vector<int> y){

 vector<int> a;
 int c = 0, size, sum;

 while(y.size() < x.size())
    y.push_back(0);

  size = x.size();

  for(int i = 0; i <= size - 1; i ++){

      sum = x[i] + y[i] + c;

      if(sum == 3){

          c = 1;
          sum = 1;
      }
      else if(sum == 2){

                c = 1;
                sum = 0;
           }
           else
                c = 0;

      a.push_back(sum);

      if(i == size - 1 && c == 1)

           a.push_back(c);
  }

  return a;
}

/* 
The operand with fewer digits is padded with 0’s

For each digit:

 If the sum of the two digits and the carry is an odd number, then the difference is 1

 Else the difference is 0

 Extra zeros are removed*/

vector<int> subtract(vector<int>  x, vector<int> y){

        int c = 0;
        vector<int> d(0);

        while(y.size() < x.size())
                y.push_back(0);

        int size = x.size();

        for (int i = 0; i <= size - 1; i++){

                if((c + x[i] + y[i]) % 2 != 0)
                        d.push_back(1);
                else
                        d.push_back(0);
                if((c + y[i] + d[i]) >= 2)
                        c = 1;
                else
                        c = 0;
        }

        size = d.size() - 1;

        while(d[size] == 0 && size >= 0){

                d.pop_back();
                size = d.size() - 1;
        }

        return  d;
}
bool greaterThan(vector<int> r, vector<int> y){

   bool greater;

   int b1, b2;

    if(r.size() > y.size())

        greater = true;

    else if(r.size() < y.size())

           greater = false;

         else{

                b1 = binary(r);

                b2 = binary(y);

                if(b1 >= b2)

                    greater = true;
        }

    return greater;
}
int binary(vector<int> x){

   int size, position = 1, Sum = 0;

   size = x.size() - 1;


   for(int i = 0; i <= size; i++){

       for(int j = 0; j <= (i - 1); j++)

            position = position * 2;

        Sum = Sum + position * x[i];

        position = 1;

   }

   return Sum;
}

// This function multiplies the two inputs by using a series of shift and add operation

vector<int> multiply(vector<int> x, vector<int> y){

   vector<int> z(0);


   for(int i = (y.size() - 1); i >= 0; i--){

       z.insert (z.begin(), 0);

       if(y[i] == 1){

           if(z.size() < x.size())

                z = add(x, z);

            else

                z = add(z, x);
       }
   }

   return z;
}

