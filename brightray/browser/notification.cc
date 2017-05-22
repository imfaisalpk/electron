// Copyright (c) 2015 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "brightray/browser/notification.h"

#include "brightray/browser/notification_delegate.h"
#include "brightray/browser/notification_presenter.h"

namespace brightray {

Notification::Notification(NotificationDelegate* delegate,
                           NotificationPresenter* presenter)
    : delegate_(delegate),
      presenter_(presenter),
      weak_factory_(this) {
}

Notification::~Notification() {
  delegate()->NotificationDestroyed();
}

void Notification::NotificationClicked() {
  delegate()->NotificationClick();
  Destroy();
}

void Notification::NotificationDismissed() {
  delegate()->NotificationClosed();
  Destroy();
}

void Notification::NotificationFailed() {
  delegate()->NotificationFailed();
  Destroy();
}

void Notification::Destroy() {
  presenter()->RemoveNotification(this);
}

}  // namespace brightray