/*
 * (C) Copyright 2015 Kurento (http://kurento.org/)
 *
 * All rights reserved. This program and the accompanying materials
 * are made available under the terms of the GNU Lesser General Public License
 * (LGPL) version 2.1 which accompanies this distribution, and is available at
 * http://www.gnu.org/licenses/lgpl-2.1.html
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 */

#ifndef __KMS_BASE_RTP_SESSION_H__
#define __KMS_BASE_RTP_SESSION_H__

#include <gst/gst.h>
#include "kmssdpsession.h"
#include "sdpagent/kmssdpagent.h"
#include "sdpagent/kmssdppayloadmanager.h"
#include "kmsbasesdpendpoint.h"
#include "kmsirtpconnection.h"
#include "kmsconnectionstate.h"

G_BEGIN_DECLS


/* #defines don't like whitespacey bits */
#define KMS_TYPE_BASE_RTP_SESSION \
  (kms_base_rtp_session_get_type())
#define KMS_BASE_RTP_SESSION(obj) \
  (G_TYPE_CHECK_INSTANCE_CAST((obj),KMS_TYPE_BASE_RTP_SESSION,KmsBaseRtpSession))
#define KMS_BASE_RTP_SESSION_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_CAST((klass),KMS_TYPE_BASE_RTP_SESSION,KmsBaseRtpSessionClass))
#define KMS_IS_BASE_RTP_SESSION(obj) \
  (G_TYPE_CHECK_INSTANCE_TYPE((obj),KMS_TYPE_BASE_RTP_SESSION))
#define KMS_IS_BASE_RTP_SESSION_CLASS(klass) \
  (G_TYPE_CHECK_CLASS_TYPE((klass),KMS_TYPE_BASE_RTP_SESSION))
#define KMS_BASE_RTP_SESSION_CAST(obj) ((KmsBaseRtpSession*)(obj))

typedef struct _KmsBaseRtpSession KmsBaseRtpSession;
typedef struct _KmsBaseRtpSessionClass KmsBaseRtpSessionClass;

struct _KmsBaseRtpSession
{
  KmsSdpSession parent;

  GHashTable *conns;
  KmsConnectionState conn_state;
};

struct _KmsBaseRtpSessionClass
{
  KmsSdpSessionClass parent_class;
};

GType kms_base_rtp_session_get_type (void);

KmsBaseRtpSession * kms_base_rtp_session_new (KmsBaseSdpEndpoint * ep, guint id);
KmsIRtpConnection * kms_base_rtp_session_get_connection_by_name (KmsBaseRtpSession * self, const gchar * name);
KmsIRtpConnection * kms_base_rtp_session_get_connection (KmsBaseRtpSession * self, SdpMediaConfig * mconf);

G_END_DECLS
#endif /* __KMS_BASE_RTP_SESSION_H__ */