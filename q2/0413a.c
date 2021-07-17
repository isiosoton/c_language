# include<stdio.h>
# include<stdlib.h>
# include<time.h>
# include<math.h>
# define l 100 /* system size */
# define n 50 /* time lengths */
# define k 8 /* n of rules */
int main(){
    int i,t;
    int rule[k];
    int state[l]; /* state=0 state=1*/
    int next_state[l];
        for(i=0;i<l;i++)
        {
            state[i]=0; //一旦全てのセルを状態 0 に
        }
    state[50] = 1; //真ん中だけ状態 1
    /* ------ Rule -------*/
    rule[0] = 0;
    rule[1] = 1;
    rule[2] = 0;
    rule[3] = 1;
    rule[4] = 1;
    rule[5] = 0;
    rule[6] = 1;
    rule[7] = 0;
    /* --------------------*/
    int a = l-1;
    for(t=0;t<n;t++){ //ここから世代ループ
        for (i=0; i<=a; i++){
            if(i==0){
                if(state[i]==0){
                    if(state[l-1]==0 && state[i+1]==0){
                        next_state[i]=rule[0];
                    }
                    if(state[l-1]==0 && state[i+1]==1){
                        next_state[i]=rule[1];
                    }
                    if(state[l-1]==1 && state[i+1]==0){
                        next_state[i]=rule[4];
                    }
                    if(state[l-1]==1 && state[i+1]==1){
                        next_state[i]=rule[5];
                    }
                } else {
                    if(state[l-1]==0 && state[i+1]==0){
                        next_state[i]=rule[2];
                    }
                    if(state[l-1]==0 && state[i+1]==1){
                        next_state[i]=rule[3];
                    }
                    if(state[l-1]==1 && state[i+1]==0){
                        next_state[i]=rule[6];
                    }
                    if(state[l-1]==1 && state[i+1]==1){
                        next_state[i]=rule[7];
                    }
                }
            } else if (i==a){
                if(state[i]==0){
                    if(state[i-1]==0 && state[0]==0){
                        next_state[i]=rule[0];
                    }
                    if(state[i-1]==0 && state[0]==1){
                        next_state[i]=rule[1];
                    }
                    if(state[i-1]==1 && state[0]==0){
                        next_state[i]=rule[4];
                    }
                    if(state[i-1]==1 && state[0]==1){
                        next_state[i]=rule[5];
                    }
                } else {
                    if(state[i-1]==0 && state[0]==0){
                        next_state[i]=rule[2];
                    }
                    if(state[i-1]==0 && state[0]==1){
                        next_state[i]=rule[3];
                    }
                    if(state[i-1]==1 && state[0]==0){
                        next_state[i]=rule[6];
                    }
                    if(state[i-1]==1 && state[0]==1){
                        next_state[i]=rule[7];
                    }
                }
            } else {
                if(state[i]==0){
                    if(state[i-1]==0 && state[i+1]==0){
                        next_state[i]=rule[0];
                    }
                    if(state[i-1]==0 && state[i+1]==1){
                        next_state[i]=rule[1];
                    }
                    if(state[i-1]==1 && state[i+1]==0){
                        next_state[i]=rule[4];
                    }
                    if(state[i-1]==1 && state[i+1]==1){
                        next_state[i]=rule[5];
                    }
                } else {
                    if(state[i-1]==0 && state[i+1]==0){
                        next_state[i]=rule[2];
                    }
                    if(state[i-1]==0 && state[i+1]==1){
                        next_state[i]=rule[3];
                    }
                    if(state[i-1]==1 && state[i+1]==0){
                        next_state[i]=rule[6];
                    }
                    if(state[i-1]==1 && state[i+1]==1){
                        next_state[i]=rule[7];
                    }
                }
            }
            if(state[i]==0){
                printf(" ");
            } else {
                printf("%d",state[i]);
            }
        }
        for (i=0; i<=a; i++){
            state[i] = next_state[i];
        }
        printf("\n");
    }
}