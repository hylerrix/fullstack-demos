import { useRouter, BlitzPage } from "blitz"
import Layout from "app/components/Layout"
import { LoginForm } from "app/models/auth/components/LoginForm"

const LoginPage: BlitzPage = () => {
  const router = useRouter()

  return (
    <div>
      <LoginForm
        onSuccess={() => {
          const next = router.query.next ? decodeURIComponent(router.query.next as string) : "/"
          router.push(next)
        }}
      />
    </div>
  )
}

LoginPage.redirectAuthenticatedTo = "/"
LoginPage.getLayout = (page) => <Layout title="Log In">{page}</Layout>

export default LoginPage
