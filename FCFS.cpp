#include <iostream>
#include <algorithm>
#include <iomanip>
#include <numeric>
using namespace std; 

int main() {
    int a[10];
    cout << "How many processes are needed: ";
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        {
            cout<<"Enter the process P"<<i+1<<": ";
            cin >> a[i];
        }
    int count=0;

    int e[100], w[100];
    fill(begin(e), end(e), 0);
    fill(begin(w), end(w), 0);
    
    w[0]=0;
    for(int i=0;i<n;i++)
    {
        count+=a[i];
        e[i]=count;
        w[i+1]=e[i];
    }

    for(int i=0;i<n;i++)
        cout<<"-----------";
    cout<<endl<<"0";
    for(int i=0;i<n;i++)
        cout<<"|_"<<"P:"<<i+1<<"="<<e[i]<<"_|";
    cout<<"\n";
    for(int i=0;i<n;i++)
            cout<<"-----------";
        cout<<"\n\n";
    
        for(int i=0;i<27;i++)
        cout<<"-";
    printf("\n");
    cout<<"Name"<<"  "<<"Burst"<<"  "<<"T-around"<<"  "<<"Wait"<<endl;
    for(int i=0;i<27;i++)
        cout<<"-";
    printf("\n");
    for(int i=0;i<n;i++)
        cout<<"P "<<i+1<<":"<<setw(4)<<a[i]<<setw(7)<<e[i]<<setw(10)<<w[i]<<endl;

    cout<<"\n\n";
    int e_sum= accumulate(begin(e), end(e), 0), w_sum=accumulate(begin(w), end(w), -e[n-1]);
    cout<<"The avg Turn around time : "<<(float)e_sum/n<<endl<<"The avg waiting time : "<<(float)w_sum/n;
    cout<<"\n\n";

    return 0;
}
