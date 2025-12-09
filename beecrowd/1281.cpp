#include <iostream>
#include <iomanip>

int compareStrings(const char *str1, const char *str2) {
    while (*str1 && *str2 && *str1 == *str2) {
        str1++;
        str2++;
    }
    return static_cast<unsigned char>(*str1) - static_cast<unsigned char>(*str2);
}

int main() {
    int N;
    std::cin >> N;
    
    for (int i = 0; i < N; i++) {
        int M;
        std::cin >> M;
        
        char productNames[1000][51];
        double productPrices[1000];
        
        for (int j = 0; j < M; j++) {
            std::cin >> productNames[j] >> productPrices[j];
        }
        
        int P;
        std::cin >> P;
        double total = 0.0;
        
        for (int j = 0; j < P; j++) {
            char productName[51];
            int quantity;
            std::cin >> productName >> quantity;
            
            for (int k = 0; k < M; k++) {
                if (compareStrings(productName, productNames[k]) == 0) {
                    total += quantity * productPrices[k];
                    break;
                }
            }
        }
        
        std::cout << "R$ " << std::fixed << std::setprecision(2) << total << std::endl;
    }
    
    return 0;
}