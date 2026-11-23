class ProductOfNumbers {
public:
    vector<int>res{1};
    ProductOfNumbers() {
    }
    void add(int num) {
        if(num==0) res={1};
        else res.push_back(res.back()*num);
    }
    
    int getProduct(int k) {
        int n=res.size();
        if(k>=n) return 0;
        return res[n-1]/res[n-1-k];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */