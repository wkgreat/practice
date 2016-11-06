#include<stdio.h>

/* a sort of sort method  ^_^ */
int quicksort(int *, int l, int r);
int insertsort(int *, int);
int selectsort(int *, int);
int bubblesort(int *, int);

int main(void)
{
	int a[]={4,2,45,14,258,14,25,35,14,58};
	//quicksort(a,0,9);
	//insertsort(a,10);
	//selectsort(a,10);
	bubblesort(a,10);
	int i;
	for(i=0;i<10;++i)
	  printf("%d ", a[i]);
	printf("\n");
	return 0;
}

int quicksort(int *R, int l, int r)
{
	int i=l, j=r;
	int t;
	if(l<r)
	{
		t = R[l];
		while(i!=j)
		{
			while(i<j && R[j]>t) --j;
			if(i<j)
			{
				R[i] = R[j];
				++i;
			}
			while(i<j && R[i]<t) ++i;
			if(i<j)
			{
				R[j] = R[i];
				--j;
			}
		}
		R[i] = t;
		quicksort(R,l,i-1);
		quicksort(R,i+1,r);
	}

	return 0;
}

int insertsort(int *R, int n)
{
	int i,j;
	int t;
	for(i=1;i<n;++i)
	{
		t=R[i];
		j=i-1;
		while(t<R[j])
		  R[j+1]=R[j--];
		R[j+1]=t;
	}

	return 0;
}

int selectsort(int *R, int n)
{
	int i,j,k,t;
	for(i=0;i<n-1;++i)
	{
		k=i;
		for(j=i+1;j<n;++j)
		{
			if(R[j]<R[k])
			  k=j;
		}
		t=R[i];
		R[i]=R[k];
		R[k]=t;
	}
	return 0;
}


int bubblesort(int *R, int n)
{
	int i,j,t;
	int f;
	for(i=n-1;i>0;--i)
	{
		for(j=0,f=0;j<i;++j)
		{
			if(R[j+1]<R[j])
			{
				f=1;
				t=R[j];
				R[j]=R[j+1];
				R[j+1]=t;
			}
		}

		if(!f) return 0;
	}
	return 0;
}









