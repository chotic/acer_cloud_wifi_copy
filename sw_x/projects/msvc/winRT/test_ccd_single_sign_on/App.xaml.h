﻿//
// App.xaml.h
// Declaration of the App class.
//

#pragma once

#include "App.g.h"

namespace test_ccd_single_sign_on
{
	/// <summary>
	/// Provides application-specific behavior to supplement the default Application class.
	/// </summary>
	ref class App sealed
	{
	public:
		App();
		virtual void OnLaunched(Windows::ApplicationModel::Activation::LaunchActivatedEventArgs^ args) override;

	private:
		void OnSuspending(Platform::Object^ sender, Windows::ApplicationModel::SuspendingEventArgs^ e);
	};
}
