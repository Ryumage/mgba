/* Copyright (c) 2013-2016 Jeffrey Pfau
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */
#include <mgba/core/lockstep.h>

void mLockstepInit(struct mLockstep* lockstep) {
	lockstep->attached = 0;
	lockstep->transferActive = 0;
#ifndef NDEBUG
	lockstep->transferId = 0;
#endif

#if MGBA_LOCK_STEP_USE_MUTEX
	MutexInit(&lockstep->mutex);
	ConditionInit(&lockstep->cond);
#endif
}

void mLockstepDeinit(struct mLockstep* lockstep) {
#if MGBA_LOCK_STEP_USE_MUTEX
	MutexDeinit(&lockstep->mutex);
	ConditionDeinit(&lockstep->cond);
#endif
}

// TODO: Migrate nodes
