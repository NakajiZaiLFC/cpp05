#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main()
{
	try
	{
		// 官僚の作成
		std::cout << "=== 官僚の作成 ===" << std::endl;
		Bureaucrat intern("インターン", 140);
		Bureaucrat executor("実行官", 40);
		Bureaucrat president("社長", 1);

		std::cout << intern << std::endl;
		std::cout << executor << std::endl;
		std::cout << president << std::endl;

		// フォームの作成
		std::cout << "\n=== フォームの作成 ===" << std::endl;
		ShrubberyCreationForm shrubbery("garden");
		RobotomyRequestForm robotomy("target");
		PresidentialPardonForm pardon("criminal");

		std::cout << shrubbery << std::endl;
		std::cout << robotomy << std::endl;
		std::cout << pardon << std::endl;

		// 署名のテスト
		std::cout << "\n=== 署名のテスト ===" << std::endl;

		// インターンが庭園作成フォームに署名（成功するはず）
		intern.signForm(shrubbery);

		// インターンがロボトミーフォームに署名（失敗するはず）
		intern.signForm(robotomy);

		// 実行官がロボトミーフォームに署名（成功するはず）
		executor.signForm(robotomy);

		// 社長が大統領赦免フォームに署名（成功するはず）
		president.signForm(pardon);

		// 実行のテスト
		std::cout << "\n=== 実行のテスト ===" << std::endl;

		// インターンが庭園作成フォームを実行（失敗するはず）
		intern.executeForm(shrubbery);

		// 実行官が庭園作成フォームを実行（成功するはず）
		executor.executeForm(shrubbery);

		// 実行官がロボトミーフォームを実行（成功するはず）
		executor.executeForm(robotomy);

		// 実行官が大統領赦免フォームを実行（失敗するはず）
		executor.executeForm(pardon);

		// 社長が大統領赦免フォームを実行（成功するはず）
		president.executeForm(pardon);

		// 未署名フォームの実行テスト
		std::cout << "\n=== 未署名フォームの実行テスト ===" << std::endl;
		ShrubberyCreationForm unsignedForm("unsignedGarden");
		president.executeForm(unsignedForm);
	}
	catch (const std::exception &e)
	{
		std::cout << "例外が発生しました: " << e.what() << std::endl;
	}

	return 0;
}
