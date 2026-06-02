#include <iostream>
#include <memory>
#include <string>

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

void RenderUI(const GUIFactory& factory) {
    auto button = factory.CreateButton();
    auto checkbox = factory.CreateCheckbox();
    std::cout << "[" << factory.PlatformName() << "] "
              << button->Render() << " (" << button->GetStyle() << "), "
              << checkbox->Render() << " (" << checkbox->GetStyle() << ")\n";
}

int main() {
    WindowsFactory windows;
    MacFactory mac;
    RenderUI(windows);
    RenderUI(mac);
    return 0;
}
