#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
# define l 100 // system size
# define n 50 /* time lengths */
# define k 8 /* n of rules */
int main(void){
    srand((unsigned)time(NULL)); // 注 1
    int i,t, state[l]; // state[i]=0 -> death, state[i]=1 -> alive
    int rule[k];
    int next_state[l];
    double density=0.8 ,rn[l];
        for(i=0;i<l;i++){
            rn[i]=(rand()/(RAND_MAX+1.0));
            if(rn[i]<=density){ // 注 2
                state[i]=1;
            } else {
                state[i]=0;
            }
        }// end for
    int a = l-1;
    /* ------ Rule -------*/
    rule[0] = 0;
    rule[1] = 0;
    rule[2] = 0;
    rule[3] = 1;
    rule[4] = 1;
    rule[5] = 1;
    rule[6] = 0;
    rule[7] = 1;
    /* --------------------*/
    printf("車占有密度:%.1lf\n",density);
    for(t=0;t<n;t++){ //ここから世代ループ
        for (i=0; i<l; i++){
            if(i==0){
                if(state[i]==0){
                    if(state[a]==0 && state[i+1]==0){
                        next_state[i]=rule[0];
                    }
                    if(state[a]==0 && state[i+1]==1){
                        next_state[i]=rule[1];
                    }
                    if(state[a]==1 && state[i+1]==0){
                        next_state[i]=rule[4];
                    }
                    if(state[a]==1 && state[i+1]==1){
                        next_state[i]=rule[5];
                    }
                }
                if(state[i]==1){
                    if(state[a]==0 && state[i+1]==0){
                        next_state[i]=rule[2];
                    }
                    if(state[a]==0 && state[i+1]==1){
                        next_state[i]=rule[3];
                    }
                    if(state[a]==1 && state[i+1]==0){
                        next_state[i]=rule[6];
                    }
                    if(state[a]==1 && state[i+1]==1){
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
                }
                if(state[i]==1){
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
                } 
                if(state[i]==1){
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
                printf("　");
            }
            if(state[i]==1){
                printf("🚙");
                //printf("%d",state[i]);
            }
                //printf("%d",state[i]);            
        }
        for (i=0; i<l; i++){
            state[i] = next_state[i];
        }
        printf("\n");
    }
}