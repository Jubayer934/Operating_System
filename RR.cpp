#include <iostream>
#include <algorithm>
#include <iomanip>
#include <numeric>
using namespace std; 
int k=0, frame[100],z=1,m[100],n[100],o=0;
/*
k for total burst
frame for count FrameByFrame
z for maintaining frame
m and n for execute a process identify
o for maintain m&n
w for waiting
*/

int check_process(int a[],int r);
void Waiting_time(int R[],int r, int b[], int w[]);
void frame_count(int r, int a[], int n);

int main() {
    int a[100];
    cout << "Give the frame size = ";

    int n;
    cin >> n;

    cout << "How many processes are there : ";
    int r;
    cin >> r;
    for (int i = 0; i < r; i++)
    {
        cout<<"Enter the size of each process P"<<i+1<<" : ";
        cin >> a[i];
    }
    int b[100];
    copy(begin(a),end(b),b);   /// Make a copy of Burst time

    int R[100];  /// To count the round of each burst

    for(int i=0;i<r;i++)  ///Counting Rounds
    {
        R[i]=a[i]/n;
        if(a[i]%n!=0)
            R[i]++;
    }

    frame[0]=0;  
    while(true){
        int temp=check_process(a,r);
        if (temp==1)
            frame_count(r, a, n);
        else
            break;
    }
    printf("\n\n");
    for(int i=0;i<z;i++)
        cout<<"----------";
    cout<<endl<<frame[z];
    for(int i=0;i<z;i++)
        cout<<"|_"<<"P:"<<i+1<<"="<<frame[i]<<"_|";

    printf("\n");
    for(int i=0;i<z;i++)
        cout<<"----------";
    cout<<"\n\n";
    int w[100];
    fill(begin(w), end(w), 0);
    Waiting_time(R,r,b,w);
    for(int i=0;i<27;i++)
        cout<<"-";
    printf("\n");
    cout<<"Name"<<"  "<<"Burst"<<"  "<<"T-around"<<"  "<<"Wait"<<endl;
    for(int i=0;i<27;i++)
        cout<<"-";
    printf("\n");
    for(int i=0;i<r;i++)
        cout<<"P "<<i+1<<":"<<setw(4)<<b[i]<<setw(7)<<m[i]<<setw(9)<<w[i]<<endl;

    cout<<"\n\n";
    int wait_sum=accumulate(begin(w), end(w), 0), ex_sum=accumulate(begin(m), end(m), 0);

    cout<<"The avg waiting time : "<<(float)wait_sum/r<<endl;
    cout<<"The avg turn-around time : "<<(float)ex_sum/r<<endl;

    return 0;
}

int check_process(int a[],int r)
{
    for(int i=0;i<r;i++)
    {
        if(a[i]>0)
            return 1;
    }
    return 0;
}

void frame_count(int r, int a[], int n) {

    for (int i = 0; i < r; i++) {
        if (a[i] <= 0)
            continue;
        if(a[i]<n)
        { 
            k+=a[i];
            frame[z]=k;
            z++;
            a[i]=0;
        }
        else
        {
            k+=n;
            frame[z]=k;
            z++;
            a[i]-=n;
        }
    }    
}
void Waiting_time(int R[],int r, int b[], int w[])
{
    int j=0,i=-1;

    while(j<z)
    {
        if(i==(r-1))
            i=0;
        else
            i++;
        if(R[i]<=0)
            continue;
        if(R[i]==1)
        {
            m[o]=frame[j+1];
            n[o]=i;
            o++;
            if(o==r)
                break;
        }
        j++;
        R[i]--;
        }
        for(int i=0;i<r;i++)
            for(int j=i+1;j<r;j++)
            if(n[i]>n[j])
                {
                    swap(m[i],m[j]);
                    swap(n[i],n[j]);
                }
        for(int i=0;i<r;i++)
            w[i]=m[i]-b[i];
}


    


