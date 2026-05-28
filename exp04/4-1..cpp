# include <iostream>
using namespace std;
int main(){
    int arr[10];
    for(int i=0;i<10;i++){
        cin>>arr[i];
    }
    int max=arr[0];
    for(int i=1;i<10;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }   
    cout<<max<<endl;
    int min=arr[0];
    for(int i=1;i<10;i++){
        if(arr[i]<min){
            min=arr[i];
        }
    }
    cout<<min<<endl;
    int sum =0;
    for(int i=0;i<10;i++){
        sum+=arr[i];
    }
    cout<<sum/10<<endl;
    return 0;
}