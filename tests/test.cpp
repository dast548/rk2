#include <memory>
#include <string>
#include <gtest/gtest.h>

class Button {
public:
    virtual ~Button() = default;
    virtual std::string Render() const = 0;
    virtual std::string GetStyle() const = 0;
};

class Checkbox {
public:
    virtual ~Checkbox() = default;
    virtual std::string Render() const = 0;
    virtual std::string GetStyle() const = 0;
};

class WindowsButton : public Button {
public:
    std::string Render() const override { return "WindowsButton"; }
    std::string GetStyle() const override { return "Flat"; }
};

class WindowsCheckbox : public Checkbox {
public:
    std::string Render() const override { return "WindowsCheckbox"; }
    std::string GetStyle() const override { return "Square"; }
};

class MacButton : public Button {
public:
    std::string Render() const override { return "MacButton"; }
    std::string GetStyle() const override { return "Rounded"; }
};

class MacCheckbox : public Checkbox {
public:
    std::string Render() const override { return "MacCheckbox"; }
    std::string GetStyle() const override { return "Circle"; }
};

class GUIFactory {
public:
    virtual ~GUIFactory() = default;
    virtual std::unique_ptr<Button> CreateButton() const = 0;
    virtual std::unique_ptr<Checkbox> CreateCheckbox() const = 0;
    virtual std::string PlatformName() const = 0;
};

class WindowsFactory : public GUIFactory {
public:
    std::unique_ptr<Button> CreateButton() const override { return std::make_unique<WindowsButton>(); }
    std::unique_ptr<Checkbox> CreateCheckbox() const override { return std::make_unique<WindowsCheckbox>(); }
    std::string PlatformName() const override { return "Windows"; }
};

class MacFactory : public GUIFactory {
public:
    std::unique_ptr<Button> CreateButton() const override { return std::make_unique<MacButton>(); }
    std::unique_ptr<Checkbox> CreateCheckbox() const override { return std::make_unique<MacCheckbox>(); }
    std::string PlatformName() const override { return "Mac"; }
};

TEST(WindowsFactory, CreatesWindowsButton) {
    WindowsFactory factory;
    auto button = factory.CreateButton();
    EXPECT_EQ(button->Render(), "WindowsButton");
    EXPECT_EQ(button->GetStyle(), "Flat");
}

TEST(WindowsFactory, CreatesWindowsCheckbox) {
    WindowsFactory factory;
    auto checkbox = factory.CreateCheckbox();
    EXPECT_EQ(checkbox->Render(), "WindowsCheckbox");
    EXPECT_EQ(checkbox->GetStyle(), "Square");
}

TEST(WindowsFactory, PlatformName) {
    WindowsFactory factory;
    EXPECT_EQ(factory.PlatformName(), "Windows");
}

TEST(MacFactory, CreatesMacButton) {
    MacFactory factory;
    auto button = factory.CreateButton();
    EXPECT_EQ(button->Render(), "MacButton");
    EXPECT_EQ(button->GetStyle(), "Rounded");
}

TEST(MacFactory, CreatesMacCheckbox) {
    MacFactory factory;
    auto checkbox = factory.CreateCheckbox();
    EXPECT_EQ(checkbox->Render(), "MacCheckbox");
    EXPECT_EQ(checkbox->GetStyle(), "Circle");
}

TEST(MacFactory, PlatformName) {
    MacFactory factory;
    EXPECT_EQ(factory.PlatformName(), "Mac");
}

TEST(AbstractFactory, ProductsAreIndependent) {
    WindowsFactory wf;
    MacFactory mf;
    auto wb = wf.CreateButton();
    auto mb = mf.CreateButton();
    EXPECT_NE(wb->Render(), mb->Render());
    EXPECT_NE(wb->GetStyle(), mb->GetStyle());
}
