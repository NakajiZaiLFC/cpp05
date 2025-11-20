#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {
    // 1. フォーム作成時の例外テスト
    std::cout << "--- Form Construction Test ---" << std::endl;
    try {
        Form invalid("InvalidForm", 0, 50); // エラーになるはず
    } catch (std::exception& e) {
        std::cout << "Exception caught: " << e.what() << std::endl;
    }

    // 2. 正常系と署名テスト
    std::cout << "\n--- Signing Test ---" << std::endl;
    try {
        // 官僚を作成 (等級: 50)
        Bureaucrat bob("Bob", 50);
        
        // フォームを作成
        // formA: 署名に等級40が必要 (Bobには無理)
        Form formA("Tax Form", 40, 100);
        // formB: 署名に等級60が必要 (Bobならいける)
        Form formB("Lunch Form", 60, 100);

        // フォーム情報の表示
        std::cout << formA << std::endl;
        std::cout << formB << std::endl;

        // 署名テスト 1: 失敗するはず
        std::cout << "\n[Attempt 1]" << std::endl;
        bob.signForm(formA);
        std::cout << "Form A status: " << (formA.getSignatureStatus() ? "Signed" : "Not Signed") << std::endl;

        // 署名テスト 2: 成功するはず
        std::cout << "\n[Attempt 2]" << std::endl;
        bob.signForm(formB);
        std::cout << "Form B status: " << (formB.getSignatureStatus() ? "Signed" : "Not Signed") << std::endl;

    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }

    return 0;
}
