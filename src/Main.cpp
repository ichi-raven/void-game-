﻿
#include <Siv3D.hpp> // OpenSiv3D v0.4.2
#include <HamFramework.hpp>

#include "GameParam.hpp"
#include "Title.hpp"
#include "Game.hpp"
#include "Result.hpp"

using App = SceneManager<String, GameParam>;

void Main()
{
	App app;

	app.add<Title>(U"Title");
	app.add<Game>(U"Game");
	app.add<Result>(U"Result");

	app.get()->windowWidth  = Window::ClientWidth();
	app.get()->windowHeight = Window::ClientHeight();
	app.get()->endWithDead = false;

	while (System::Update())
		if (!app.update())
			break;
}

//
// = アドバイス =
// Debug ビルドではプログラムの最適化がオフになります。
// 実行速度が遅いと感じた場合は Release ビルドを試しましょう。
// アプリをリリースするときにも、Release ビルドにするのを忘れないように！
//
// 思ったように動作しない場合は「デバッグの開始」でプログラムを実行すると、
// 出力ウィンドウに詳細なログが表示されるので、エラーの原因を見つけやすくなります。
//
// = お役立ちリンク =
//
// OpenSiv3D リファレンス
// https://siv3d.github.io/ja-jp/
//
// チュートリアル
// https://siv3d.github.io/ja-jp/tutorial/basic/
//
// よくある間違い
// https://siv3d.github.io/ja-jp/articles/mistakes/
//
// サポートについて
// https://siv3d.github.io/ja-jp/support/support/
//
// Siv3D Slack (ユーザコミュニティ) への参加
// https://siv3d.github.io/ja-jp/community/community/
//
// 新機能の提案やバグの報告
// https://github.com/Siv3D/OpenSiv3D/issues
//
