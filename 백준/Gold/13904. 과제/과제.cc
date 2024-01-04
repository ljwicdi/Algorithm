    #include <iostream>
    #include <cstdlib>
    using namespace std;
    #define MAX_SIZE 1500
    int N;
    typedef int (*PriorityComp) (int date1, int score1, int date2, int score2);
    typedef struct homework
    {
        int date;
        int score;
    } HOMEWORK;
    typedef struct _heap
    {
        HOMEWORK heap[MAX_SIZE];
        int numOfData;
        PriorityComp comp;    // 우선순위 결정 기준을 제공하는 함수
    } HEAP;

    int compF(int date1, int score1, int date2, int score2)
    {
        if(date1>date2)
            return 1;
        else if(date1==date2)
        {
            if(score1>=score2)
                return 1;
            else
                return 0;
        }
        return 0;
    }
    void Init(HEAP * h,PriorityComp f)
    {
        h->numOfData = 0;
        h->comp = f;
    }


    bool IsEmpty(HEAP * h)
    {
        if(h->numOfData==0)
            return true;
        else
            return false;
    }

    int GetParentIdx(int idx)
    {
        return idx/2;
    }

    int GetRChildIdx(int idx)
    {
        return idx*2+1;
    }

    int GetLChildIdx(int idx)
    {
        return idx*2;
    }



    int GetPChildIdx(HEAP * h, int idx)
    {
        if(GetLChildIdx(idx)==h->numOfData)
        {
            return GetLChildIdx(idx);
        }
        if(GetLChildIdx(idx)>h->numOfData)
        {
            return 0;
        }
        if(h->comp(h->heap[GetLChildIdx(idx)].date, h->heap[GetLChildIdx(idx)].score, h->heap[GetRChildIdx(idx)].date, h->heap[GetRChildIdx(idx)].score)>0)
        {
            return GetLChildIdx(idx);
        }
        else
        {
            return GetRChildIdx(idx);
        }
    }

    void Insert(HEAP * h, int date, int score)
    {
        int idx = h->numOfData + 1;

        while(idx!=1)
        {
            if(h->comp(date ,score, h->heap[GetParentIdx(idx)].date, h->heap[GetParentIdx(idx)].score)>0)
            {
                h->heap[idx] = h->heap[GetParentIdx(idx)];
                idx = GetParentIdx(idx);
            }
            else
                break;
        }
        h->numOfData++;
        h->heap[idx].date = date;
        h->heap[idx].score = score;
        
    }
    int Delete(HEAP * h)
    {
        if(IsEmpty(h))
            return 0;
        int rData;
        rData = h->heap[1].score;
        int start = 1;
        int idx = h->numOfData;
        int childIdx;
        while(childIdx = GetPChildIdx(h, start))
        {
            if(h->comp(h->heap[childIdx].date, h->heap[childIdx].score,  h->heap[idx].date, h->heap[idx].score)>0)
            {
                h->heap[start] = h->heap[childIdx];
                start = childIdx;
            }
            else
                break;
        }
        h->heap[start] = h->heap[idx];
        h->numOfData--;
        return rData;
    }

    HOMEWORK Delete2(HEAP * h)
    {
        HOMEWORK rData;
        rData = h->heap[1];
        int start = 1;
        int idx = h->numOfData;
        int childIdx;
        while(childIdx = GetPChildIdx(h, start))
        {
            if(h->comp(h->heap[childIdx].date, h->heap[childIdx].score,  h->heap[idx].date, h->heap[idx].score)>0)
            {
                h->heap[start] = h->heap[childIdx];
                start = childIdx;
            }
            else
                break;
        }
        h->heap[start] = h->heap[idx];
        h->numOfData--;
        return rData;
    }
    void DateDown(HEAP * h,int k)
    {
        for(int i=1;i<=h->numOfData;i++)
        {
            if(h->heap[i].date>=k)
                h->heap[i].date = (h->heap[i].date) - 1;

        }
    }
    bool PriorityChk(HEAP * h)
    {
        if(h->heap[1].date == 0)
            return true;
        else
            return false;
    }

    int main(void)
    {
        int totalSum = 0;
        ios::sync_with_stdio(0), cin.tie(0), cout.tie(0); 
        HEAP * h = (HEAP*)malloc(sizeof(HEAP));
        Init(h,compF);
        int N;
        int date, score;
        HOMEWORK temp[2000];
        int idx = 0;
        cin>>N;
        cin.ignore();
        int max = 0;
        for(int i=0;i<N;i++)
        {
            cin>>date>>score;
            if(date>max)
                max = date;
            Insert(h,date,score);
        }

        for(int i=max;i>=1;i--)
        {
            while(PriorityChk(h))
            {
                Delete(h);
            }
            if(i<=h->heap[1].date)
            {
                DateDown(h,i);
                totalSum = totalSum + Delete(h);
                while(!IsEmpty(h))
                    temp[idx++] = Delete2(h); 
                for(int p=0;p<idx;p++)
                {
                    Insert(h,temp[p].date,temp[p].score);
                }
                idx = 0;
            }
            else
                continue;
        }
        cout<<totalSum<<endl;
        return 0;
    }