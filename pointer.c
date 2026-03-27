#include <stdio.h>

int ucle(int *p);

int main() {
    int n;
    scanf("%d",&n);
    int arr[n], arrOverlap[n];
    int i;
    int j;
    int b;
    
    for (i = 0; i < n; i++) {
        arr[i] = i + 1; //arr 에 1 ~n 값을 넣는다
        arrOverlap[i] = 0;  // overlap 모든 배열칸에 0을 넣는다
    }
    for(i = 0; i < n; i++) 
    { 
        if (i == 0) {
            continue;
        }
        for (j = i + 1; j <= n; j++) { // i가 2라는 가정으로 arr의 [안에 값은 2] 이고 3 %3 ==0 arr값에 3이 들어감 으로써 그 수에 최대 공약수가 들어간다
            if (arr[j] % (i + 1) == 0) // 1,2,3,4,5,6,7,8,9,10....36  % (i+1) = 6
                arr[j] = (i + 1);
        }
    }
    
    for (i = 0; i < n; i++) {
        //printf("%d , %d \n", arr[i], arrOverlap[i]);
    }
    
    
    for(i = 0; i < n; i++) 
    {
        b = 0;
        //printf("----------- %d ----------- \n", arr[i]); // arr[i]를 출력해
        for (j = 0; j <= n; j++) // /j 가 n만큼 반복하며 검사
        {
            if (arrOverlap[j] == arr[i]) //만약 오버랩과 arr이 같다면 b에 1을 대입 그리고 break
            {
                b = 1;
                //printf("%d , %d \n", arr[i], arrOverlap[j]);  // arr = 3 or =0 2
                break;
            }
        }
        
        if (b) //b가 1이 되었다면 참이기에 컨티뉴가 실행되어 아래 프린트와 식을 행하지 않고 위로 돌아감
            continue;
        printf("%d\n", arr[i]); //만약 컨티뉴가 되지않앗다면 arr[i]를 출력
        arrOverlap[i] = arr[i]; //오버랩배열 안에 arr에 현재 있는 수를 추가해 다음 for문때 그 수가 있다면 오버랩과 arr이 같다는 이프문이 되어 똑같은 수는 출력되지않고 컨티뉴 됨 
    }
    return 0;
}
