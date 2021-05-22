import { Suspense } from "react"
import { Link, BlitzPage, useMutation, Routes, getSession, useSession, getAntiCSRFToken } from "blitz"
import Layout from "app/components/Layout"
import { useCurrentUser } from "app/hooks/useCurrentUser"
import logout from "app/models/auth/mutations/logout"

/*
 * This file is just for a pleasant getting started page for your new app.
 * You can delete everything in here and start from scratch if you like.
 */

const UserInfo = () => {
  const currentUser = useCurrentUser()
  const [logoutMutation] = useMutation(logout)

  if (currentUser) {
    return (
      <>
        <button
          className="button small"
          onClick={async () => {
            await logoutMutation()
          }}
        >
          Logout
        </button>
        <div>
          User id: <code>{currentUser.id}</code>
          <br />
          User role: <code>{currentUser.role}</code>
        </div>
      </>
    )
  } else {
    return (
      <>
        <Link href={Routes.SignupPage()}>
          <a className="button small">
            <strong>Sign Up</strong>
          </a>
        </Link>
        <Link href={Routes.LoginPage()}>
          <a className="button small">
            <strong>Login</strong>
          </a>
        </Link>
      </>
    )
  }
}

export async function getServerSideProps({ req, res }) {
  const session = await getSession(req, res)
  console.log('get session on the server user id:', session.userId)
  return {
    props: {
      sessionPublicDataFromServerSide: session.$publicData,
    }, // will be passed to the page component as props
  }
}

const Home: BlitzPage = ({ sessionPublicDataFromServerSide }) => {
  const session = useSession({ suspense: false })
  const antiCSRFToken = getAntiCSRFToken()

  return (
    <div>
      <h1>Hello, world!</h1>

      <p>get session from client - useSession: {JSON.stringify(session)}</p>
      <p>get session from server side - getServerSideProps: {JSON.stringify(sessionPublicDataFromServerSide)}</p>
      <p>antiCSRFToken: {antiCSRFToken} </p>

      <Suspense fallback="Loading...">
        <UserInfo />
      </Suspense>
    </div>
  )
}

Home.suppressFirstRenderFlicker = true
Home.getLayout = (page) => <Layout title="Home">{page}</Layout>

export default Home
