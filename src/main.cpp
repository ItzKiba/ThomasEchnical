#include <Geode/Geode.hpp>
#include <Geode/Loader.hpp>
#include <Geode/modify/ProfilePage.hpp>

using namespace geode::prelude;

class $modify(ProfilePage) {
	
	static void onModify(auto &self) {
        self.setHookPriority("ProfilePage::loadPageFromUserInfo", -1);
    }

	void loadPageFromUserInfo(GJUserScore* score) {
		ProfilePage::loadPageFromUserInfo(score);

		if (score->m_userID != 3047677) {
			return;
		}

		CCLabelBMFont* font;
		if (Loader::get()->isModLoaded("cvolton.betterinfo")) {
			auto btn = static_cast<CCMenuItemSpriteExtra*>(this->m_mainLayer->getChildByID("main-menu")->getChildByID("cvolton.betterinfo/username-button"));
			CCObject* search;
			CCARRAY_FOREACH(btn->getChildren(), search) {
				if (auto newLabel = static_cast<CCLabelBMFont*>(search)) {
					font = newLabel;
				}
			}
		} else {
			font = static_cast<CCLabelBMFont*>(this->m_mainLayer->getChildByID("username-label"));
		}

		if (font == nullptr) {
			return;
		}

		auto tint1 = CCTintTo::create(0.25f, 180, 255, 0);
		auto tint2 = CCTintTo::create(0.25f, 180, 0, 255);
		auto seq = CCSequence::create(tint1, tint2, nullptr);
		auto rseq = CCRepeatForever::create(seq);
		font->runAction(rseq);
		font->setString("Thomas Echincal");

		auto amba = CCLabelBMFont::create("RATE AMBA", "bigFont.fnt");
		amba->setColor({255, 160, 255});
		auto ambachild = this->m_mainLayer->getChildByID("floor-line");
		amba->setPosition(ambachild->getPosition());
		amba->setScale(0.4f);
		this->m_mainLayer->addChild(amba);
	}
};
