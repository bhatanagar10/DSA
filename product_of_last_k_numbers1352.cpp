class ProductOfNumbers {
public:
    vector<int>vec;
    
    ProductOfNumbers() {
        vec.push_back(1);
    }
    
    void add(int num) {
        if(num == 0){
            vec.clear();
            vec.push_back(1);
            return;
        }
        
        vec.push_back(vec.back() * num);
    }
    
    int getProduct(int k) {
        
        if(k >= vec.size()){
            return 0;
        }
        int n = vec.size();        
        return ( vec[n-1] / vec[n-1-k] );
    }
};