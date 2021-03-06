/* KDevelop MSVC Support
 *
 * Copyright 2015 Ennio Barbaro <enniobarbaro@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */


#include "msvcbuilder.h"
#include "devenvjob.h"

KJob * MsvcBuilder::build(KDevelop::ProjectBaseItem* item)
{
    return runDevEnv(item, DevEnvJob::BuildCommand);
}

KJob * MsvcBuilder::clean(KDevelop::ProjectBaseItem* item)
{
    return runDevEnv(item, DevEnvJob::CleanCommand);
}

DevEnvJob* MsvcBuilder::runDevEnv(KDevelop::ProjectBaseItem  * item, DevEnvJob::CommandType type)
{
    if ( KDevelop::ProjectBuildFolderItem * solItem = dynamic_cast<KDevelop::ProjectBuildFolderItem*>(item) )
    {
        DevEnvJob * job = new DevEnvJob(nullptr, solItem, type );
        job->setAutoDelete(true);
        return job;
    }
    
    return nullptr;
}
