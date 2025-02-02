#include "Global.h"

class CustomUpgrades
{
public:
    CustomUpgrades()
    {

    };

    std::vector<UpgradeBox*> GetPage(int page)
    {
        return systemUpgradeBoxes[page];
    }

    int GetNumPages()
    {
        return systemUpgradeBoxes.size();
    }

    void OnInit(Upgrades *upgrades, ShipManager *ship);
    void MouseClick(int mX, int mY);
    void MouseMove(int mX, int mY);
    void MouseRightClick(int mX, int mY);
    void OnRender();
    void Close();
    void OnLoop();
    void AddSystemBox(UpgradeBox* box);
    void ConfirmUpgrades();

    Upgrades *orig = nullptr;
    std::vector<std::vector<UpgradeBox*>> systemUpgradeBoxes;
    TextInput *renameInput = nullptr;
    bool allowRename = false;
    bool allowButton = false;

    static CustomUpgrades* GetInstance()
    {
        return &instance;
    }
private:
    Button *leftButton = nullptr;
    Button *rightButton = nullptr;
    Button *renameButton = nullptr;

    int currentPage = 0;

    static CustomUpgrades instance;
};

struct SystemNoPurchaseThreshold
{
    static std::string to_string(int cost)
    {
        if (!enabled || cost < threshold) return std::to_string(cost);
        return replace;
    }
    
    static bool enabled;
    static int threshold;
    static std::string replace;
};
