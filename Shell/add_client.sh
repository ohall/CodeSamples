#!/bin/bash
set -u
set -e

git add .

git reset -q include s44jr_client_flex/src/config/s44jr_local_config.xml s44jr_client_flex/src/config/s44jr_config.xml s44jr_client_flex/.actionScriptProperties s44jr_client_flex/.flexProperties s44jr_client_core/.actionScriptProperties  s44jr_shared/.actionScriptProperties s44jr_shared/.flexLibProperties s44jr_activities/.actionScriptProperties s44jr_activities/.flexProperties


echo "============================================================="
git status
echo "added all, but reset s44jr_config, s44jr_local_config, properties files and include."
echo "============================================================="