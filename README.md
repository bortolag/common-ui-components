# Common UI Components

A work in progress library of ready to use UI components for Unreal Engine 5.

## List of components

 1. Navigation Dots Widget (`UNavigationDots`) — UMG content widget wrapping a Slate `SNavigationDots`; displays a row of selectable dots with optional left/right navigation buttons. Configurable dot count, per-dot padding, and style via `FNavigationDotsStyle`. Exposes `SetSelectedDot`, `GetSelectedDot`, `SetNumberOfDots`, `SetDotsPadding`, and `ShowNavigationButtons` as BlueprintCallable/Pure functions. Fires `OnDotSelected` (Blueprint-assignable delegate) whenever a new dot is selected.
 2. ViewModel Base (`UCommonViewModelBase`) — MVVM ViewModel base class; dispatches `Initialize` / `Deinitialize` virtuals on construction and destruction, skipping CDOs.
 3. Activatable Widget Base (`UCommonActivatableWidgetBase`) — CommonUI activatable widget base; calls `PlayIn` / `PlayOut` BlueprintNativeEvents on activation/deactivation and exposes `OnPlayIn` / `OnPlayOut` multicast delegates (C++ and Blueprint variants). Call `NotifyPlayInComplete` / `NotifyPlayOutComplete` when animations finish.
 4. List Entry Widget Base (`UCommonListEntryWidgetBase`) — CommonUI button base implementing `IUserObjectListEntry`; automatically wires a ViewModel when the list item object is a `UMVVMViewModelBase`.
 5. Dynamic Entry Box (`UCommonDynamicEntryBox`) — `UDynamicEntryBox` wrapper with a `SetListEntries` helper that creates one entry per ViewModel and wires each via MVVM.
 6. UI Function Library (`UCommonUIFunctionLibrary`) — Blueprint function library; provides `GetViewModel<T>` (C++ template) and `SetViewModel` (BlueprintCallable) helpers for wiring MVVM views.
