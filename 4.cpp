#include <iostream>
using namespace std;

int main(){
  int a[100][100] = {{0}};
  int b[100][100] = {{0}};
  long c[100][100] = {{0}};
  int n,m,l;

  cin >> n >> m >> l;
  for(int in = 0; in < n; in++){
    for(int jm = 0; jm < m; jm++){
      cin >> a[in][jm];
    }
  }
  for(int jm = 0; jm < m; jm++){
    for(int kl = 0; kl < l; kl++){
      cin >> b[jm][kl];
    }
  }
  for(int jm = 0; jm < m; jm++){
    for(int kl = 0; kl < l; kl++){
      cin >> b[jm][kl];
    }
  }
  for(int in = 0; in < n; in++){
    for(int jm = 0; jm < m; jm++){
      for(int kl = 0; kl < l; kl++){
        c[in][kl] += a[in][jm] * b[jm][kl];
      }
    }
  }
  for(int in = 0; in < n; in++){
    for(int jl = 0; jl < l; jl++){
      cout << c[in][jl];
      if(jl != l-1){
        cout << " ";
      }
    }
    cout << endl;
  }
}
