#include<stdio.h>

int main(){
		int n,p,i,j,com[1003];
			scanf("%d",&n);
				for(i=0;i<n;i++){
							scanf("%d",com+i);
								}
					p=0;
						i=-1;
							j=0;
								while(p<n){
											if(i<0||i>=n){
															j++;
																	}
													if(j&1)
																	i++;
															else
																			i--;
																	if(i>=0&&i<n&&com[i]!=-1&&com[i]<=p){
																					p++;
																								com[i]=-1;
																										}
																		}
									printf("%d\n",j-1);
										return 0;
}