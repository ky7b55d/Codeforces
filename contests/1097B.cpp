#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;
using ll = long long;

const int MOD=998244353;

ll powerCalc(ll base,ll exp){
    ll res=1;
    base%=MOD;
    while(exp>0){
        if(exp%2==1)res=(res*base)%MOD;
        base=(base*base)%MOD;
        exp/=2;
    }
    return res;
}

ll modInv(ll val){
    return powerCalc(val,MOD-2);
}

ll sortAndCount(vector<ll> &seq,int leftB,int rightB,vector<ll> &aux){
    if(leftB>=rightB) return 0;
    int midP=leftB+((rightB-leftB)/2);
    ll invCnt=sortAndCount(seq,leftB,midP,aux)+sortAndCount(seq,midP+1,rightB,aux);
    int ptrL=leftB,ptrR=midP+1,ptrOut=leftB;
    while(ptrL<=midP && ptrR<=rightB){
        if(seq[ptrL]<=seq[ptrR]){
            aux[ptrOut++]=seq[ptrL++];
        }
        else{
            aux[ptrOut++]=seq[ptrR++];
            invCnt+=(midP-ptrL+1);
        }
    }
    while(ptrL<=midP)aux[ptrOut++]=seq[ptrL++];
    while(ptrR<=rightB)aux[ptrOut++]=seq[ptrR++];
    for(int idx=leftB;idx<=rightB;++idx)seq[idx]=aux[idx];
    return invCnt;
}

void solve() {
    ll numElem;
    cin >> numElem;
    vector<ll> seqA(numElem),seqB(numElem);
    for(int idx=0;idx<numElem;++idx) cin >> seqA[idx];
    for(int idx=0;idx<numElem;++idx) cin >> seqB[idx];
    if(numElem==1){
        cout << 0 << "\n"; return;
    }
    ll baseInv=0;
    for(int idx1=0;idx1<numElem;++idx1){
        for(int idx2=idx1+1;idx2<numElem;++idx2){
            if(seqA[idx1]>seqA[idx2]) baseInv++;
        }
    }
    sort(seqB.begin(),seqB.end());
    vector<ll> prodSeq(numElem*numElem);
    for(int idx1=0;idx1<numElem;++idx1){
        for(int idx2=0;idx2<numElem;++idx2){
            prodSeq[idx1*numElem+idx2]=seqA[idx1]*seqB[idx2];
        }
    }
    vector<ll> auxSeq(numElem*numElem);
    ll globalInv=sortAndCount(prodSeq,0,numElem*numElem-1,auxSeq);
    ll finalNum=(globalInv%MOD-(numElem*(baseInv%MOD))%MOD+MOD)%MOD;
    ll finalDen=(numElem*(numElem-1))%MOD;
    ll expectedVal=(finalNum*modInv(finalDen))%MOD;
    cout << expectedVal << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}