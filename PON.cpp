        #include <iostream>
        using namespace std;
            unsigned long binpower(unsigned long long a, unsigned long long b, unsigned long long m) {
                a %= m;
                unsigned long long res = 1;
                while (b > 0) {
                    if (b & 1)
                        res = res * a % m;
                    a = a * a % m;
                    b >>= 1;
                }
                return res;
            }
            bool probablyPrimeFermat(unsigned long long int n, int iter) {
                if (n < 4)
                    return n == 2 || n == 3;
             
                for (int i = 0; i < iter; i++) {
                    long long int a = (unsigned long long)2 + (unsigned long long)rand() % (n - 3);
                    if (binpower(a, n - 1, n) != 1)
                        return false;
                }
                return true;
            }
            int main() {
            	// your code goes here
            	int t;
            	cin >> t;
            	while(t--){
            		unsigned long long int n;
            		cin>> n;
            		if(probablyPrimeFermat(n,100)) cout<< "YES\n";
            		else cout << "NO\n";
            	}
            	return 0;
