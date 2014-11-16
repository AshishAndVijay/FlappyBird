﻿//
// Birdy.xaml.cpp
// Implementation of the Birdy class
//

#include "pch.h"
#include "Birdy.xaml.h"

using namespace FlappyBird;

using namespace Platform;
using namespace Windows::Foundation;
using namespace Windows::Foundation::Collections;
using namespace Windows::UI::Xaml;
using namespace Windows::UI::Xaml::Controls;
using namespace Windows::UI::Xaml::Controls::Primitives;
using namespace Windows::UI::Xaml::Data;
using namespace Windows::UI::Xaml::Input;
using namespace Windows::UI::Xaml::Media;
using namespace Windows::UI::Xaml::Navigation;

// The User Control item template is documented at http://go.microsoft.com/fwlink/?LinkId=234236

Birdy::Birdy()
{
	InitializeComponent();

	Life();
}

void Birdy::Life()
{
	TimeSpan liferate = TimeSpan();

	auto timer = ref new DispatcherTimer();

	timer->Tick+=ref new EventHandler<Object ^>(this, &Birdy::OnTick);
	timer->Start();
}

void Birdy::OnTick(Object ^sender, Object ^args)
{
	auto currentWindow = Window::Current;
	auto bounds = currentWindow->Bounds;

	auto maxTop = bounds.Height + Height;
	auto birdTop = Canvas::GetTop(this);

	if (birdTop < maxTop)
		Canvas::SetTop(this, Canvas::GetTop(this) + 3);
}
