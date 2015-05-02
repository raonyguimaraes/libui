// 23 april 2015
#include "test.h"

uiMenu *fileMenu;
uiMenuItem *newItem;
uiMenuItem *openItem;
uiMenuItem *quitItem;
uiMenu *editMenu;
uiMenuItem *undoItem;
uiMenuItem *checkItem;
uiMenuItem *accelItem;
uiMenuItem *prefsItem;
uiMenu *testMenu;
uiMenuItem *enabledItem;
uiMenuItem *enableThisItem;
uiMenuItem *forceCheckedItem;
uiMenuItem *forceUncheckedItem;
uiMenu *moreTestsMenu;
uiMenuItem *quitEnabledItem;
uiMenuItem *prefsEnabledItem;
uiMenuItem *aboutEnabledItem;
uiMenuItem *checkEnabledItem;
uiMenu *helpMenu;
uiMenuItem *helpItem;
uiMenuItem *aboutItem;

static void enableItemTest(uiMenuItem *item, uiWindow *w, void *data)
{
	if (uiMenuItemChecked(item))
		uiMenuItemEnable(uiMenuItem(data));
	else
		uiMenuItemDisable(uiMenuItem(data));
}

static void forceOn(uiMenuItem *item, uiWindow *w, void *data)
{
	uiMenuItemSetChecked(enabledItem, 1);
}

static void forceOff(uiMenuItem *item, uiWindow *w, void *data)
{
	uiMenuItemSetChecked(enabledItem, 0);
}

void initMenus(void)
{
	fileMenu = uiNewMenu("File");
	newItem = uiMenuAppendItem(fileMenu, "New");
	openItem = uiMenuAppendItem(fileMenu, "Open");
	quitItem = uiMenuAppendQuitItem(fileMenu);

	editMenu = uiNewMenu("Edit");
	undoItem = uiMenuAppendItem(editMenu, "Undo");
	uiMenuItemDisable(undoItem);
	uiMenuAppendSeparator(editMenu);
	checkItem = uiMenuAppendCheckItem(editMenu, "Check Me\tTest");
	accelItem = uiMenuAppendItem(editMenu, "A&ccele&&rator T_es__t");
	prefsItem = uiMenuAppendPreferencesItem(editMenu);

	testMenu = uiNewMenu("Test");
	enabledItem = uiMenuAppendCheckItem(testMenu, "Enable Below Item");
	uiMenuItemSetChecked(enabledItem, 1);
	enableThisItem = uiMenuAppendItem(testMenu, "This Will Be Enabled");
	uiMenuItemOnClicked(enabledItem, enableItemTest, enableThisItem);
	forceCheckedItem = uiMenuAppendItem(testMenu, "Force Above Checked");
	uiMenuItemOnClicked(forceCheckedItem, forceOn, NULL);
	forceUncheckedItem = uiMenuAppendItem(testMenu, "Force Above Unchecked");
	uiMenuItemOnClicked(forceUncheckedItem, forceOff, NULL);

	moreTestsMenu = uiNewMenu("More Tests");
	quitEnabledItem = uiMenuAppendCheckItem(moreTestsMenu, "Quit Item Enabled");
	uiMenuItemSetChecked(quitEnabledItem, 1);
	prefsEnabledItem = uiMenuAppendCheckItem(moreTestsMenu, "Preferences Item Enabled");
	uiMenuItemSetChecked(prefsEnabledItem, 1);
	aboutEnabledItem = uiMenuAppendCheckItem(moreTestsMenu, "About Item Enabled");
	uiMenuItemSetChecked(aboutEnabledItem, 1);
	uiMenuAppendSeparator(moreTestsMenu);
	checkEnabledItem = uiMenuAppendCheckItem(moreTestsMenu, "Check Me Item Enabled");
	uiMenuItemSetChecked(checkEnabledItem, 1);

	helpMenu = uiNewMenu("Help");
	helpItem = uiMenuAppendItem(helpMenu, "Help");
	aboutItem = uiMenuAppendAboutItem(helpMenu);

	uiMenuItemOnClicked(quitEnabledItem, enableItemTest, quitItem);
	uiMenuItemOnClicked(prefsEnabledItem, enableItemTest, prefsItem);
	uiMenuItemOnClicked(aboutEnabledItem, enableItemTest, aboutItem);
	uiMenuItemOnClicked(checkEnabledItem, enableItemTest, checkItem);
}
