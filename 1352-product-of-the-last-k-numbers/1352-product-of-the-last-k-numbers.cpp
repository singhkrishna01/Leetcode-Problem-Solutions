class ProductOfNumbers {
public:
    vector<int> prefixProd;
    ProductOfNumbers() {
        prefixProd = {1};
    }
    
    void add(int num) {
        if(num == 0) {
            prefixProd = {1};
        }
        else prefixProd.push_back(prefixProd.back()*num);
    }
    
    int getProduct(int k) {
        int size = prefixProd.size();
        if(size-k-1 < 0) return 0;
        int prod = prefixProd[size-1]/prefixProd[size-k-1];
        return prod;
    }
};